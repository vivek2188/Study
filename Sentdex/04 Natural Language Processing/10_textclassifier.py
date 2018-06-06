'''
Despite coming packed with some classifiers, NLTK is mainly a toolkit focused on natural language processing, and not machine learning specifically. 
A module that is focused on machine learning is scikit-learn, which is packed with a large array of machine learning algorithms which are optimized in C. 
Luckily NLTK has recognized this and comes packaged with a special classifier that wraps around scikit learn. 
In NLTK, this is: nltk.classify.scikitlearn, specifically the class:  SklearnClassifier is what we're interested in.
This allows us to port over any of the scikit-learn classifiers that are compatible, which is most. 
'''
import nltk
import random
from nltk.corpus import movie_reviews
import pickle
from nltk.classify.scikitlearn import SklearnClassifier
from sklearn.naive_bayes import MultinomialNB,GaussianNB,BernoulliNB

documents = []
for category in movie_reviews.categories():
    for fileid in movie_reviews.fileids(category):
        review = movie_reviews.words(fileid)
        documents.append((review,category))
random.shuffle(documents)

all_words = []
for w in movie_reviews.words():
    all_words.append(w.lower())

all_words = nltk.FreqDist(all_words)
#print(all_words.most_common(15))

word_features = list(all_words.keys())[:3000]

def find_features(document):
    words = set(document)
    features = {}
    for w in word_features:
        features[w] = (w in words)
    return features

featuresets = [(find_features(rev),category) for rev,category in documents]

training_set = featuresets[:1900]
test_set = featuresets[1900:]

#classifier = nltk.NaiveBayesClassifier.train(training_set)
classifier_f = open('naivebayes.pickle','rb')
classifier = pickle.load(classifier_f)
classifier_f.close()
print("Original Naive Bayes Classifier Accuracy:",nltk.classify.accuracy(classifier,test_set)*100)
classifier.show_most_informative_features(15)

#save_classifier = open('naivebayes.pickle','wb')
#pickle.dump(classifier,save_classifier)
#save_classifier.close()


multiNB = SklearnClassifier(MultinomialNB())
multiNB.train(training_set)
print("Multinomial Naive Bayes Classifier Accuracy:",nltk.classify.accuracy(multiNB,test_set)*100)

bernoulliNB = SklearnClassifier(BernoulliNB())
bernoulliNB.train(training_set)
print("Bernoulli Naive Bayes Classifier Accuracy:",nltk.classify.accuracy(bernoulliNB,test_set)*100)
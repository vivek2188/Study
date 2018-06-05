#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Importing the dataset
data = pd.read_csv('Restaurant_Reviews.tsv',delimiter='\t',quoting=3)

#Cleaning the texts
import re
import nltk
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
ps = PorterStemmer()

corpus = []
for indx in range(1000):
    review = re.sub('[^a-zA-Z]',' ',data['Review'][indx])
    review = review.lower()
    review = review.split()
    """
    from nltk.tokenize import word_tokenize
    review = word_tokenize(review)
    """
    stop_words = set(stopwords.words('english'))
    review = [ps.stem(word) for word in review if word not in stop_words]
    review = ' '.join(review)
    corpus.append(review)

#Creating Bag of Words Model
from sklearn.feature_extraction.text import CountVectorizer
cv = CountVectorizer(max_features=475)
X = cv.fit_transform(corpus).toarray()
y = data.iloc[:,-1].values 

#Splitting into the training and test set
from sklearn.cross_validation import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.1,random_state=0)

#Fitting to the Naive Bayes Model
from sklearn.naive_bayes import GaussianNB
classifier = GaussianNB()
classifier.fit(X_train,y_train)

#Predicting the result for the test set
y_pred = classifier.predict(X_test)

#Confusion Matrix
from sklearn.metrics import confusion_matrix
cm = confusion_matrix(y_test,y_pred)
print(cm)
print('Accuracy:',classifier.score(X_test,y_test)*100)
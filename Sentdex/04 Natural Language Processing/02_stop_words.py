'''
    Stopwords are useless. It's better to get rid of them at the time of preprocessing.
'''
#Importing the libraries
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

example_sentence = "This is an example showing off stop word filtration."
print('Raw Sentence:')
print(word_tokenize(example_sentence))
print('-----------------------')

stop_words = set(stopwords.words('english'))

words = word_tokenize(example_sentence)
filtered_sentence = []

for word in words:
    if word not in stop_words:
        filtered_sentence.append(word)
print('Filtered Sentence:')
print(filtered_sentence)
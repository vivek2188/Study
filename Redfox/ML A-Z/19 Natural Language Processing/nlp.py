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
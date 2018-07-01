import nltk
from nltk.tokenize import word_tokenize
from nltk.stem import WordNetLemmatizer
from nltk.corpus import stopwords
import numpy as np
import random
import pickle
from collections import Counter

lemmatizer = WordNetLemmatizer
n_lines = 1e7

stop_words = stopwords.words('english')
print(stop_words)

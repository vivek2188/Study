'''
A very similar operation to stemming is called lemmatizing. 
The major difference between these is, as you saw earlier, stemming can often create non-existent words.
So, your root stem, meaning the word you end up with, is not something you can just look up in a dictionary.
A root lemma, on the other hand, is a real word. 
Many times, you will wind up with a very similar word, but sometimes, you will wind up with a completely different word.
'''
import nltk
from nltk.stem import WordNetLemmatizer
lemmatizer = WordNetLemmatizer()
print(lemmatizer.lemmatize("better",pos="a"))
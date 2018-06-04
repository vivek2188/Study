#Importing the libraries
from nltk.tokenize import sent_tokenize,word_tokenize
'''
Tokenising - form of grouping things
             word tokenisers , sentence tokenisers
corpora - body of text ex:medical journals , presidental speeches
Lexicon - words and their meaning 
investor-speak ... regular english-speak
investor-speak 'bull' : someone who is positive about the market
english-speak 'bull'  : animal
'''
#Sample Paragraph
example_text = 'Hello there Mr. Smith, how are you doing today? The weather is great and Python is awesome. The sky is blue. You should not eat cardboard.'

print('Sentences:')
for sentence in sent_tokenize(example_text):
    print(" ",sentence)
print('-------------------------------')
print('Words:')
for word in word_tokenize(example_text):
    print(word,end="  ")
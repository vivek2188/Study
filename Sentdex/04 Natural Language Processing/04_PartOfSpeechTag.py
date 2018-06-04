'''
Part of Speech tagging does exactly what it sounds like, it tags each word in a sentence with the part of speech for that word. 
This means it labels words as noun, adjective, verb, etc. PoS tagging also covers tenses of the parts of speech.
'''
#Importing the libraries
import nltk
from nltk.corpus import state_union
from nltk.tokenize import PunktSentenceTokenizer

train_text = state_union.raw("2005-GWBush.txt")
sample_text = state_union.raw("2006-GWBush.txt")

custom_sent_tokenizer = PunktSentenceTokenizer(train_text)
tokenized = custom_sent_tokenizer.tokenize(sample_text)

def process_content():
    try:
        for sent in tokenized:
            words = nltk.word_tokenize(sent)
            tags = nltk.pos_tag(words)
            print(tags)
    except Exception as e:
        print(str(e))

process_content()
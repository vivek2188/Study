'''
Part of the NLTK Corpora is WordNet. 
It wouldn't totally classify WordNet as a Corpora, if anything it is really a giant Lexicon, but, either way, it is super useful. 
With WordNet we can do things like look up words and their meaning according to their parts of speech, we can find synonyms, antonyms, and even examples of the word in use. 
'''
from nltk.corpus import wordnet

#Synonym set
syns = wordnet.synsets('program')
print(syns[0].name())

#The word
print(syns[0].lemmas()[0].name())

#Definition
print(syns[0].definition())

#Examples
print(syns[0].examples())

synonyms,antonyms = list() , list()
for syn in wordnet.synsets("good"):
    for l in syn.lemmas():
        synonyms.append(l.name())
        if l.antonyms():
            antonyms.append(l.antonyms()[0].name())
print(set(synonyms))
print(set(antonyms))

#Similarity between the two words
word1 = wordnet.synset('ship.n.01')
word2 = wordnet.synset('pig.n.01')
print(word1.wup_similarity(word2)*100)
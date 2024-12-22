import nltk
from nltk.stem import PorterStemmer

porter = PorterStemmer()

words = ["Hello", "currently", "studying", "studied", "study", "easily", "easiness", "easy", "fairly", "fairness"]

stemmed_words = [porter.stem(word) for word in words]

for original, stemmed in zip(words, stemmed_words):
    print(f"{original} -> {stemmed}")

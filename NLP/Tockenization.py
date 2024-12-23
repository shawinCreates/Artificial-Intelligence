import nltk
from nltk.tokenize import word_tokenize, sent_tokenize

text = "Hello everyone. This is Sabin Neupane a BIT Student from BMC. I'm currently in 4th Semester"

word_tokens = word_tokenize(text)

sent_tokens = sent_tokenize(text)

print("Word Tokens:")
print(word_tokens)
print("\nSentence Tokens:")
for sentence in sent_tokens:
    print(sentence)


import nltk
from nltk.tokenize import word_tokenize, sent_tokenize

def tokenization_example():
    # Sample text
    text = "Hello everyone. This is Sabin Neupane a BIT Student from BMC. I'm currently in 4th Semester"

    # Perform word tokenization
    word_tokens = word_tokenize(text)

    # Perform sentence tokenization
    sent_tokens = sent_tokenize(text)

    # Print results
    print("Word Tokens:")
    print(word_tokens)
    print("\nSentence Tokens:")
    for sentence in sent_tokens:
        print(sentence)

tokenization_example()

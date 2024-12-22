import nltk
from nltk import pos_tag
from nltk.tokenize import word_tokenize

def pos_tagging_example():
    # Sample text
    text = "Hello everyone. This is Sabin Neupane a BIT Student from BMC. I'm currently in 4th Semester."

    # Tokenize the text
    tokens = word_tokenize(text)

    # Perform POS tagging
    tagged = pos_tag(tokens)

    # Print results
    for word, tag in tagged:
        print(f"{word}: {tag}")

pos_tagging_example()
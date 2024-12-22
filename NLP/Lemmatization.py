import nltk
from nltk.stem import WordNetLemmatizer
from nltk.tokenize import word_tokenize

# Initialize the lemmatizer
lemmatizer = WordNetLemmatizer()

# Function to perform lemmatization
def lemmatize_text(text):
    # Tokenize the input text
    words = word_tokenize(text)
    # Lemmatize each word in the tokenized list
    lemmatized_words = [lemmatizer.lemmatize(word) for word in words]
    return lemmatized_words

# Example usage
if __name__ == "__main__":
    # Input text
    input_text = "Hello everyone. This is Sabin Neupane a BIT Student from BMC. I'm currently in 4th Semester"
    
    # Perform lemmatization
    lemmatized_output = lemmatize_text(input_text)
    
    # Print the results
    print("Original Text:", input_text)
    print("Lemmatized Output:", lemmatized_output)
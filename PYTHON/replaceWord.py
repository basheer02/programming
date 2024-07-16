from ast import Str


sentence = str(input(" Enter a sentence : "))
word = str(input(" Enter replacing word : "))
replace = str(input(" Enter word to replace : "))
#sent = "hello world"
x = sentence.replace(word,replace)
print(" ",x)
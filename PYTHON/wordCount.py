fl = open("sample.txt","r")
wordCount = 0
sentCount = 0
charCount = 0
lower,upper,spec = 0,0,0

for lines in fl:
    word = lines.split()
    sentence = lines.split('.')
    
    for each in word:       
        charCount += len(each)
        for i in range(0,len(each)):
            if each[i].islower():
                lower += 1
            elif each[i].isupper():
                upper += 1
            elif each[i] != '.' and each[i] != ',' and each[i].isnumeric() == False:
                spec += 1

    sentCount += len(sentence) - 1
    wordCount += len(word)
print(" Sentences :",sentCount,"\n Words :",wordCount,"\n Characters :",
    charCount - sentCount,"\n Lower cases :",lower,"\n Upper cases :",upper,
    "\n Special characters :",spec)
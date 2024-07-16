st = input(" Enter the string : ")
count = 0
for i in st:
    if i == '{':
        count += 1
    else:
        count -= 1
    if count < 0:
        break
    
if count == 0:
    print(" String is match")
else:
    print(" String is not match")

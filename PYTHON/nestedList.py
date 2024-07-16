records = []
n = int(input(" Enter no.of students : "))
for i in range(n):
    name = str(input(" Enter name of student : "))
    mark = float(input(" Enter mark of "+name+" : "))
    records.append([mark,name])
records.sort()
secondLowest = 0
print(records)
for k in range(n):
    if records[0][0] != records[k+1][0]:
        secondLowest = records[k+1][0]
        break
for k in range(n):
    if secondLowest == records[k][0]:
        print(secondLowest)
            
            
        
#print(records)  

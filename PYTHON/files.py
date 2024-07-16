numbers = []
fl = open("sample.txt","r")
print(" File content : \n")
for line in fl:
    print(line)
    numbers.append(line.split())
print(" Prime numbers : ",end="")
for num in numbers:
    for n in num:
        flag = 0
        n = int(n)
        for i in range(2,n):
            if n % i == 0:
                flag = 1
                break
        if flag == 0:
            print(n,end=" ")
print()
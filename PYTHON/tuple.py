n = int(input(" Enter total no.of numbers : "))
ls = []
print(" Enter numbers")
for i in range(0,n):
    #num = int(input())
    ls.append(int(input()))
tup = tuple(ls)
i = 0
print(" Even tuple : ",end="")
while i < n:
    print(tup[i],end=" ")
    i += 2
i = 1
print()
print(" Odd tuple : ",end="")
while i < n:
    print(tup[i],end=" ")
    i += 2
print()
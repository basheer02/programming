#input to a list based on a pattern and find the max value

n = int(input(" Enter the size of list : "))

lst = [0 for i in range(n)]
ch = 1
s,e,num,count = 0,0,0,0
print(lst[0])
while ch:
    s,e,num = input("\n Enter the pattern : ").split(' ')
    s,e,num = int(s)-1,int(e),int(num)
    for i in range(s,e):
        lst[i] = num
    print("\n List : ",lst)
    ch = int(input("\n if you want to continue?(yes : 1 | no : 0) : "))

num = max(lst)
print("\n List : ",lst)
print(" The highest number is : ",num)

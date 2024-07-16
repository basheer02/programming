n1,n2,s = 0,1,0

def fibo(n,n1,n2):
    if n == 0:
        return 1
    s = n1 + n2
    return n1 + fibo(n-1,n2,s)
    #return s

'''
n = int(input(" Enter the n : "))
if n == 1:
    print(" 1st term : ",n1)
elif n == 2:
    print(" 2nd term : ",n2)

for i in range(2,n):
    s = n1 + n2
    n1 = n2
    n2 = s
'''
n = int(input(" Enter the n : "))
print("",n,"th term : ",fibo(n,0,1))
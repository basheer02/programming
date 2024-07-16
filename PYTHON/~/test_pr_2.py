#pallindrome of integer
'''
a = input(" enter number : ")
n = list(a)
n.reverse()
if n == list(a):
    print("pallindrome")
else:
    print("not pallindrome")  
'''
n = int(input(" Enter number : "))
s = 0
a = n
while n != 0:
    s = (s * 10) + (n%10)
    n //= 10 
if s == a or a == 0:
    print(a,"reverse is",s," : pallindrome")
else:
    print(a,"reverse is",s," : not pallindrome")
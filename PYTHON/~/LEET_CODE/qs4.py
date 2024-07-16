n = 234
s = 0
p = 1
print(" n :",n)
while(n != 0):
    num = n % 10
    s += num
    p *= num
    n = int(n/10)

print(" Product of digits :",p)
print(" Sum of digits :",s)
print(" After substraction :",p-s)
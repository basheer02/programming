n = 0b11111111111111111111111111111101
s = 0
for i in bin(n):
    if i == '1':
        s += 1
print(" The binary",bin(n)[2:]," has total",s,"\'1\' bit") 
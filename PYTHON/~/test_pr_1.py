#multiplication without arithmetic operators

a = bin(int(input(" Enter a number : ")))[2:]
b = bin(int(input(" Enter a number : ")))[2:]
t = []
for i in b:
    x = int(i)
    tm = []
    for j in a:
        y = int(a)
        tm.append(x&y)
    t.append(tm)
print(t)
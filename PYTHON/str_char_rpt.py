sub = 0
s = 'au'
if s == '':
    print(0)
elif len(s) == 1:
    print(1)
for i in range(len(s)):
    for j in range(len(s)+1):
        w = s[i:j]
        if i !=j :
            if len(w) == len(set(w)):
                if len(w) > sub:
                    sub = len(w)
print(sub)
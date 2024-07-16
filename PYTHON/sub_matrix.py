from itertools import combinations

row = int(input(' Enter no.of rows : '))
col = int(input(' Enter no.of cols : '))

mat = []

for i in range(row):
    lst = []
    print(' Enter values for row',i+1)
    for j in range(col):
        num = int(input())
        lst.append(num)
    mat.append(lst)


for i in mat:
    print(i)

lst = [i for i in range(col)]
perm = []

for i in range(2,col):
    perm += list(combinations(lst,i))

subs = []

for i in perm:
    k = i[0]
    for j in range(1,len(i)):
        if i[j] == (k + 1):
            k = i[j]
            #print(k)
        else:
            break
    if k == i[len(i)-1]:
        subs.append([i[0],i[len(i)-1]])
    
print(subs)

submatrix = []

for s in subs:
    for i in range(row):
        temp = []
        for r in range(i,row):
            temp.append(mat[r][s[0]:s[1]+1])
        submatrix.append(temp)

sums = {}
for i in submatrix:
    print(' submatrix :\n')
    s = 0
    for j in i:
        print(j)
        s += sum(j)
    sums[str(s)] = i

print(sums)
print(' Maximum submatrix : ',max(list(sums.keys())))

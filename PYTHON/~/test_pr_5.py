q = [int(i) for i in input(" Enter the queue in order : ").split()]
dq = list(set(q))
print(dq)
l = len(q)
tmp,count = 0,0

while dq != q:
    for i in range(0,l-1):
        if dq[i] != q[i]:
            tmp = dq.index(q[i])
            dq[tmp] = dq[i]
            dq[i] = q[i]
            count += 1

print("Bribe count : ",count)
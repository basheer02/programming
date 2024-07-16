#n = 3
#jump = [3,2,4]
#leaves = 4
#st = set()
#s = sum([i for i in range(1,leaves+1)])
#
#for i in jump:
#    for j in range(1,leaves + 1):
#        if i * j <= leaves:
#            st.add(i*j)
#
#print(s-sum(st))

#arr = [-1,3,-3,5]
#max_s = float('-inf')
#for i in range(len(arr)):
#    cur = 0
#    for j in range(i,len(arr)):
#        cur += arr[j]
#        max_s = max(max_s,cur)
#print(max_s)

arr = [3,1,3,3,2,2]

n = 5

a = set(arr)

dic = {val: arr.count(val) for val in a}

val = list(filter(lambda item: item > n/2,dic.values()))
print(val)
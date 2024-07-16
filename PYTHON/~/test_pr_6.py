import random
arr = [int(i) for i in input(" Enter the numbers : ").split()]
arr.sort()
lst = []
dic = {}
k = int(input(" Enter the k value : "))
key,k = 's',0
print(arr)
for i in range(0,len(arr)):
    for j in range(i+1,len(arr)):
        tmp = []
        tmp.append(arr[i])
        tmp.append(arr[j])
        s = max(tmp) - min(tmp)
        tmp.append(s)
        dic[key+str(k)] = tmp
        k += 1
        print(tmp)
print(dic)
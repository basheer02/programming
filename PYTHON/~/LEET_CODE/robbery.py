'''
Each house has a certain amount of money stashed, the only constraint stopping 
you from robbing each of them is that adjacent houses have security systems
connected and it will automatically contact the police if two adjacent houses were
broken into on the same night.
Given an integer array nums representing the amount of money of each house, return 
the maximum amount of money you can rob tonight without alerting the police
'''

def rob(a):
    l,k,su = [],0,0
    n = len(a)
    for i in range(n):
        for j in range(i+2,n):
            l.append([a[i],a[j]])
            for k in range(j+2,n):
                for x in range(2,n):
                    lst = a[j::x]
                    if len(lst) > 1:
                        lst.insert(0,a[i])
                        if lst not in l:
                            l.append(lst)

    l.append([max(a)])
    for i in range(len(l)):
        if sum(l[i]) > su:
            su = sum(l[i])
            k = i
    print(l)
    print("\n Highest pair : ",l[k])
    return su

a = [6,3,10,8,2,10,3,5,10,5,3]
print("\n Sum : ",rob(a))
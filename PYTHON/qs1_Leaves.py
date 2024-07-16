
def uneatenLeaves(arr,n,k):
    leaves = [i for i in range(1,n+1)]

    for i in arr:
        lst = []

        print('\n Catepiller',i)
        start = int(input(' Enter the leaves no. to start jump : '))

        for j in range(start,(n//2)+1):
            eatenLeaves = i * j
            if eatenLeaves > n:
                break

            lst.append(eatenLeaves)
            if eatenLeaves in leaves:
                leaves.remove(eatenLeaves)
        print(' Leaves eaten by caterpiller',i,': ',lst)

    return len(leaves)

n = int(input(' Enter no.of leaves : '))

if n < 1 or n > 104:
    print(' No.of Leaves out of range')
else:
    k = int(input(' Enter no.of caterpillers : '))
    arr = [int(i) for i in input(' Enter caterpillers : ').split(' ')]
    res = uneatenLeaves(arr,n,k)
    print(' no.of Uneaten leaves : ',res)
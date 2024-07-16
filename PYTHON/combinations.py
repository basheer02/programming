from itertools import combinations
#from itertools import permutations

lst = [1,2,3,5]

#def combinations(arr, r):
#    if r == 0:
#        return [[]]  # Return an empty list for combinations of length 0
#    if not arr:
#        return []  # Return an empty list if the input list is empty
#
#    combos = []
#    first, rest = arr[0], arr[1:]
#
#    # Generate combinations that include the first element
#    combos.extend([ [first] + subcombo for subcombo in combinations(rest, r-1) ])
#
#    # Generate combinations that exclude the first element
#    combos.extend(combinations(rest, r))
#
#    return combos

#def permutations(arr, length):
#    if length == 0:
#        return [[]]  # Return an empty list for permutations of length 0
#    if len(arr) == 0:
#        return []  # Return an empty list if the input list is empty
#
#    result = []
#    for i in range(len(arr)):
#        # Remove the current element from the list and generate permutations for the rest
#        rest = arr[:i] + arr[i+1:]
#        for perm in permutations(rest, length - 1):
#            result.append([arr[i]] + perm)
#
#    return result

def prime(n):
    for i in range(2, (n//2)+1):
        if n % i == 0:
            return False
    return True

for num in range(6,100):
    if prime(num):
        lst.append(num)

#print(lst)

comb = list(combinations(lst,2))

print(len(comb))

prim = []

for i in comb:
    print(i)
    n = sum(i)
    if prime(n):
        prim.append(n)

print(prim)

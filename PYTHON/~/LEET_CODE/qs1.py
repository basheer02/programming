low = int(input(" Enter low : "))
high = int(input(" Enter high : "))
n = 0
odd = []
l = low
while(low <= high):
    if low % 2 == 1:
        n += 1
        odd.append(low)
    low += 1

print(" Count of odd numbers :",n)
print(" The odd numbers between",l,"and",high,"are :",odd)
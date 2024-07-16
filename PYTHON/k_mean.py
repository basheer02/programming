from random import randint

def eu_dis(a,b):
    d = 0
    for i in range(len(a)):
        d += (a[i] - b[i])**2
    return (d ** .5)

n = int(input(" Enter no.of data set : "))
print(" Enter data set : ")
data = [[float(i) for i in input().split()]for i in range(n)]
print("\n Data set : ",end="")
for i in data:
    print(i,end=" ")

k = int(input("\n\n Enter no.of clusters : "))
centroids = []
while len(centroids) != k:
    temp = randint(0,n - 1)
    if data[temp] not in centroids:
        centroids.append(data[temp])
print(" Randomly chosen centroids are : ",end="")
for i in centroids:
    print(i,end=" ")
print()

clust,clust_pat,temp_pat,cl = [],[],[],["C1","C2"]
flag = 1
ind,it = 0,1
while flag:
    print("\n Iteration ",it,"\n")
    print("   Data set  |",centroids[0],"|",centroids[1],"|  Cluster")
    print("-"*50)
    for i in data:
        print(" ",i,end=" | ")
        grt = 100
        for j,k in enumerate(centroids):
            dist = round(eu_dis(i,k),2)
            print(f"{dist: ^11}|",end=" ")
            if dist < grt:
                grt = dist
                ind = j
        clust.append(centroids[ind])
        clust_pat.append(cl[ind])
        print("  ",cl[ind])

    if clust_pat != temp_pat:
        temp_cent = []
        for i in centroids:
            ind_lst,lst,count = [],[],0
            for j,k in enumerate(clust):
                if i == k:
                    count += 1
                    ind_lst.append(j)
            if count == 1:
                temp_cent.append(i)
            else:
                lst.append(round(sum(data[i][0] for i in ind_lst)/len(ind_lst),2))
                lst.append(round(sum(data[i][1] for i in ind_lst)/len(ind_lst),2))
                temp_cent.append(lst)
        centroids.clear()
        centroids = temp_cent
        flag = 1
    else:
        print("\n Final cluster centroids are : ",end="")
        for i in centroids:
            print(i,end=" ")
        flag = 0

    temp_pat = clust_pat
    it += 1
print()
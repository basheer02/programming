f = open("exp2_sim.txt","r")
data = []
for fl in f:
    data.append(fl.strip().split())

print(" DATA : \n")
for line in data:
    for d in line:
        print(d,end="\t")
    print()

data.remove(data[0])

nom_att = [int(i) - 1 for i in input("\n Enter col no.of nominal attributes : ").split()]
num_att = [int(i) - 1 for i in input(" Enter col no.of numeric attributes : ").split()]

dis_nom,dis_num,sim_nom = [],[],[]
n = len(data)
p = len(nom_att)

for i in range(n):
    temp_nom = []
    temp_snom = []
    temp_num = []
    for j in range(i+1):
        m = 0
        e = 0

        if i == j:
            temp_nom.append(0)
            temp_num.append(0)
            temp_snom.append(0)
            break  

        for k in nom_att:
            if data[i][k] == data[j][k]:
                m += 1
        temp_nom.append((p-m)/p)
        temp_snom.append(m/p)
        for k in num_att:
            e  += ((float(data[i][k]) - float(data[j][k])) ** 2)
        temp_num.append(e ** .5)

    dis_nom.append(temp_nom)
    dis_num.append(temp_num)
    sim_nom.append(temp_snom)

print("\n Dissimilarity matrix of nominal attributes : \n")
for i in dis_nom:
    for j in i:
        print(j,end="  ")
    print()

print("\n Similarity matrix of nominal attributes : \n")
for i in sim_nom:
    for j in i:
        print(j,end="  ")
    print()

print("\n Dissimilarity matrix of numeric attributes : \n")
for i in dis_num:
    for j in i:
        print(j,end="  ")
    print()
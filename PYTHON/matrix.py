r1 = int(input(" Enter no.of rows in first matrix : "))
c1 = int(input(" Enter no.of cols in first matrix : "))
r2 = int(input(" Enter no.of rows in second matrix : "))
c2 = int(input(" Enter no.of cols in second matrix : "))

mat1 = []
mat2 = []
mat3 = []

if r1 != r2 or c1 != c2:
    print("\n Matrix addition not occur ")
else:
    for k in range(1,3):
        print("\n Enter matrix",k,"elements ")
        for i in range(0,r1):
            arr = []
            for j in range(0,c1):
                arr.append(int(input()))
            if k == 1:
                mat1.append(arr)
            else:
                mat2.append(arr)


    print("\n First matrix elements\n")
    for row in mat1:
        for col in row:
            print(" ",col,end="")
        print()
    
    print("\n Second matrix elements\n")
    for row in mat2:
        for col in row:
            print(" ",col,end="")
        print()
    
    for i in range(0,r1):
        arr = []
        for j in range(0,c1):
            sum = mat1[i][j] + mat2[i][j]
            arr.append(sum)
        mat3.append(arr)
    
    print("\n Sum of matrixes\n")
    for row in mat3:
        for col in row:
            print(" ",col,end="")
        print()
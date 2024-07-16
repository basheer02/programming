def area(r,h):
    print(" Volume of cylinder : ",3.14*r*r*h)
    vol = 2 * 3.14 * r * h + 2 * 3.14 * r * r
    print(" Surface area of cylinder : ",vol)

rad = float(input(" Enter radius of cylinder : "))
ht = float(input(" Enter height of cylinder : "))
area(rad,ht)
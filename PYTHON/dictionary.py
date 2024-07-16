dic = {}
print(" 1. Add book\n 2. Update stock\n 3. Delete book\n 4. Print\n 0. Exit\n")
ch = int(input(" Enter option number : "))
while ch:
    if ch == 1:
        book = input("\n Enter book name : ")
        if dic.__contains__(book):
            print("\n",book,"already exist")
        else:
            stock = int(input(" Enter stock : "))
            dic[book] = stock
            print("\n",book,"book successfully inserted")
    elif ch == 2:
        if dic == {}:
            print("\n No books available")
        else:
            book = input("\n Enter book name to update stock : ")
            if dic.__contains__(book):
                stock = int(input(" Enter stock to update : "))
                stock += dic.get(book)
                dic.update({book : stock})
                print("\n",book,"book stock updated")
            else:
                print("\n",book," doesn't exist")
    elif ch == 3:
        if dic == {}:
            print("\n No books available")
        else:
            book = input("\n Enter book name to delete : ")
            if dic.__contains__(book):
                dic.pop(book)
                print("\n",book,"book removed successfully")
            else:
                print(book," doesn't exist")
    elif ch == 4:   
        if dic == {}:
            print("\n No books available")
        else:
            print("\n   Book    Stock\n")
            for key,value in dic.items():
                print("  ",key,"   ",value)
    else:
            print("\n Invalid choice")
    ch = int(input("\n Enter option number : "))
print("\n Exit...\n")
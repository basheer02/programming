class Stack:
    stack = []
    def __init__(self,limit):
        self.top = -1
        self.size = limit
    def push(self,value):
        if self.top >= self.size - 1 :
            print("Stack is full")
        else :
            self.top = self.top + 1
            self.stack.append(value)
    def Print(self):
            for i in range(self.top + 1):
                print(self.stack[i])
            #print(self.stack)
#if __name__ == "__main__":
size = int(input(" Enter limit of stack : "))
s = Stack(size)
for i in range(size): 
    value = int(input(" Enter value : "))
    s.push(value)
s.Print()
print("hai")
print("hello")
#s.show()
#binary tree

class Node:
    def __init__(self,data):
        self.right = None
        self.left = None
        self.data = data

    def insert(self,data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
            else:
                self.data = data
    
    def inorder(self):
        if self:
            Node.inorder(self.left)
            print(" ",self.data)
            Node.inorder(self.right)
    
    def printInorder(self):
        stack = []
        current = self
        while True:
            if current is not None:
                stack.append(current)
                current = current.left
            elif stack:
                current = stack.pop()
                print(" ",current.data)
                current = current.data
            else:
                break

d = Node(10)
d.insert(8)
d.insert(15)
d.insert(9)
d.insert(4)
d.insert(12)

d.printInorder()
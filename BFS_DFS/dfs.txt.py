class BinaryTree:
    __slots__='root'  #the list of attributes described within are the only attributes this class will ever need
    class BinaryTreeNode:
        __slots__='key','leftChild','rightChild'
        def __init__(self,rootObj):  # self variable represents the instance of object itself _init_  represents constructor in python   
            self.key = rootObj
            self.leftChild = None
            self.rightChild = None
    def __init__(self):
        self.root=None
    def insertNode(self):
        ch=1
        while(ch==1):
            data=input("Enter data")
            if self.root == None:
                self.root = self.BinaryTreeNode(data)
            else:
                t=self.BinaryTreeNode(data)
                p=self.root
                flag=0
                while(flag==0):
                    print ("Current node: ",p.key)
                    answer=input("Which Direction? ")
                    if (answer=='l'):
                        if p.leftChild == None:
                            p.leftChild = t
                            flag=1
                        else:
                            p=p.leftChild
                    if (answer=='r'):
                        if p.rightChild == None:
                            p.rightChild = t
                            flag=1
                        else:
                            p=p.rightChild
                       
            ch=int(input("Do u want more?"))    
            
        
    def printInorderTree(self,root):
        # prints the tree path
        if root == None:
            pass  #pass is a null operation. when it is executed, nothing happens. It is useful as a placeholder when a statement is required syntactically
        else:
            self.printInorderTree(root.leftChild)
            print (root.key)
            self.printInorderTree(root.rightChild)
            
    def printPreorderTree(self,root):
        # prints the tree path
        if root == None:
            pass
        else:
            print (root.key)
            self.printPreorderTree(root.leftChild)
            self.printPreorderTree(root.rightChild)

    def printPostorderTree(self,root):
        # prints the tree path
        if root == None:
            pass
        else:
            self.printPostorderTree(root.leftChild)
            self.printPostorderTree(root.rightChild)
            print (root.key)
      
               
r=BinaryTree()
r.insertNode()
print ("traversals")
print("Inorder")
r.printInorderTree(r.root)
print("POstorder")
r.printPostorderTree(r.root)
print("Preorder")
r.printPreorderTree(r.root)


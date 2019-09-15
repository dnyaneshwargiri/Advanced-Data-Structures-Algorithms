
class BinaryTree:
    __slots__='root'  #the list of attributes described within are the only attributes this class will ever need
    class BinaryTreeNode:
        __slots__='key','leftChild','rightChild'
        def __init__(self,rootObj):  # self variable represents the instance of object itself init_  represents constructor in python   
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
            
            
    def bfs(self):
            from collections import deque  # collections is high performance container datatypes
            queue = deque()  #list-like container with fast appends and pops on either end
            p=self.root
            queue.append(p)  #Add to the end
            while(len(queue)!=0):
                p=queue.popleft()  #Remove from the beginning
                print (p.key)
                if(p.leftChild !=None):
                    queue.append(p.leftChild)
                if(p.rightChild !=None):
                    queue.append(p.rightChild)
                    
    
r=BinaryTree()
r.insertNode()
print("\nBFS:")
r.bfs() 

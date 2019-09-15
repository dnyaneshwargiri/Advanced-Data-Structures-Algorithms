
#include<iostream>
using namespace std;

class node
{
  public:
    node *left,*right;
    int data;

};

class btree
{
  public:
    node *root;
     btree()
    {
        root=NULL;
    }
     node *create();
     void display(node *);
     node *copytree(node *);
     void operator=(btree &);
     node *deletenode(node *);

};
class stack1
{
   public:
    node *stack[20];
    int top;
      stack1()
      {
         top=-1;
      }


  int Isempty()
   {
       if(top==-1)
           return 1;
       else
           return 0;
   }
   int Isfull()
   {
       if(top==20-1)
       {
           return 1;
       }
       else
           return 0;
   }


   void push(node *x)
  {
  if(!Isfull())
  {
        top++;
        stack[top]=x;
  }

  }

  node *pop()
  {
      return stack[top--];
  }


};//end of class stack1


node *btree::create()
{
    node *temp,*ptr;
    char ans;
    char ch;
     root =new node;
     cout<<"\nenter the data";
     cin>>root->data;
     root->left==NULL;
     root->right==NULL;
     do
     {
         ptr= new node;
         cout<<"\n enter the next node's data ";
         cin>>ptr->data;
         ptr->left==NULL;
         ptr->right==NULL;
         temp=root;

            while(1)
            {

             cout<<"\nOn which side you want to insert(r/l)";
             cin>>ch;
             if(ch=='l')
              {
                 if(temp->left==NULL)
                 {

                     cout<<"\ndata is:"<<temp->data<<"-"<<ptr->data;
                     temp->left=ptr;
                     break;

                 }
                 else
                     temp=temp->left;
              }
             else
             {
                 if(temp->right==NULL)
                  {

                     cout<<"\ndata is:"<<temp->data<<"-"<<ptr->data;
                     temp->right=ptr;
                     break;
                  }
                  else
                     temp=temp->right;

             }

            }
             cout<<"\n do you want to insert data";
                     cin>>ans;



     }while(ans=='Y'||ans=='y');
     return root;


}//end of create fun()

void btree::display(node *root)
{
    stack1 s;
    node *current;
    current=root;
     while(1)
     {
         while(current!=NULL)
         {
             s.push(current);
             current=current->left;
         }
         if(s.Isempty())
             return;
         current=s.pop();
         cout<<current->data<<" ";
         current=current->right;
     }



}//end of display function

void btree::operator=(btree &tree)
{
    cout<<" using operator overloading:";
    node *ptr=copytree(tree.root);
    display(ptr);
}

node *btree::copytree(node *tree)
{
    node *temp= new node;
    if(tree==NULL)
        return tree;
    temp->data=tree->data;
    temp->left=copytree(tree->left);
    temp->right=copytree(tree->right);
     return temp;
}

node *btree::deletenode(node *ptr)
{
    if(ptr!=NULL)
    {
    deletenode(ptr->left);
    deletenode(ptr->right);
    delete ptr;
    }
    return NULL;

}

int main()
{

    btree t,t1;
        node *p;
        int ch;

        do{
          cout<<"\n 1.Create \n 2.Display \n 3.copy tree\n 4.delete\n enter your choice";
           cin>>ch;
           switch(ch)
           {
             case 1 :
              p=t.create();
             break;
             case 2 :
                 cout<<"\ntree is:";
              t.display(p);
             break;
             case 3:
                 cout<<"\ncopied tree ";
                  t1=t;
                  break;
             case 4:
                 cout<<"\nafter deletion";
                 p=t.deletenode(p);
                 t.display(p);
                 break;

             default:

                 cout<<"exit";
        }

        }while(ch<=4);

    return 0;
}



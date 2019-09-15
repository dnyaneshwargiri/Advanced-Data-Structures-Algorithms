

#include<iostream>
#include<string.h>
using namespace std;

class node
{
    char keyword[10];
    char meaning[10];
    node *left,*right;
    friend class binarytree;
public:
    node(char k[10],char m[10])
    {
            strcpy(this->keyword,k);
            strcpy(this->meaning,m);
            left=NULL;
            right=NULL;
    }
};

class binarytree
{
    node *root;
public:
    binarytree()
    {
        root=NULL;
    }
    node*create();
    void inorder(node *);
    node*search();
    node*update();
    node*deletenode();
    void postorder(node *current);
};

node* binarytree::create()
{
    node *temp,*ptr;
    char k[10],m[10];
    char ans;
    do
    {
        cout<<"\n Enter the word:";
        cin>>k;
        cout<<"\n Enter the Meaning:";
        cin>>m;
        temp=new node(k,m);
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            if(strcmp(ptr->keyword,temp->keyword)>0)
            {
                if(ptr->left!=NULL)
                    ptr=ptr->left;
                else
                {
                    ptr->left=temp;
                    break;
                }
            }
            else
            {
                if(ptr->right!=NULL)
                ptr=ptr->right;
                else
                {
                    ptr->right=temp;
                    break;
                }
            }
        }
    }
    cout<<"\n Do you want to add more data(y/n):";
    cin>>ans;
    }while(ans=='y' || ans=='Y');
    return root;
}

void binarytree::inorder(node *current)
{
    if(current!=NULL)
    {
        inorder(current->left);
        cout<<"\n"<<current->keyword;
        cout<<"\t :"<<current->meaning;
        inorder(current->right);
    }
    else
        return;
}
void binarytree::postorder(node *current)
{
    if(current!=NULL)
    {postorder(current->right);
    cout<<"\n"<<current->keyword;
    cout<<"\t :"<<current->meaning;
    postorder(current->left);
    }
    else
        return;
}

node* binarytree::search()
{
    char key[10];
    node *ptr=root;
    cout<<"\n Enter the word which you want to search:";
    cin>>key;
    int count=0;
    int flag=0;
    while(ptr!=NULL)
    {
        count++;
        if(strcmp(ptr->keyword,key)==0)
        {
            cout<<"\n Data found ";
            cout<<"\n Number of comparisons:"<<count;
            flag=1;
            break;
        }
        else
        {
            if(strcmp(ptr->keyword,key)>0)
                ptr=ptr->left;
            else
                ptr=ptr->right;
        }
    }
    if(flag==0)
    {
        cout<<"\n Data not found";
    }
    else
    return ptr;
}

node* binarytree::update()
{

    char key[10];
    node *ptr=root;
    cout<<"\n Enter the data to be updated:";
    cin>>key;
    int count=0;
    int flag=0;
    while(ptr!=NULL)
    {
        count++;
        if(strcmp(ptr->keyword,key)==0)
        {
            cout<<"\n Data found";
            cout<<"\n Number of comparisons:"<<count;
            cout<<ptr->keyword<<"\t"<<ptr->meaning;
            cout<<"\n Enter the meaning";
            cin>>ptr->meaning;
            flag=1;
            break;
        }
        else
        {
            if(strcmp(ptr->keyword,key)>0)
                ptr=ptr->left;
            else
                ptr=ptr->right;
        }
    }
    if(flag==0)
    {
        cout<<"\n Data not found";
    }
}

node* binarytree::deletenode()
{
    char key[10];
        node *ptr=root;
        node *parent;
        parent=root;
        cout<<"\n Enter the data which you want to delete:";
        cin>>key;

        while(ptr!=NULL)
        {
            if(strcmp(ptr->keyword,key)==0)
            {
                cout<<"\n Data found";
                if(ptr->left==NULL && ptr->right==NULL)
                {
                   //cout<<"\n Parents data:"<<parent->keyword;
                  if(parent->left==ptr)
                        parent->left=NULL;
                    else
                        parent->right=NULL;
                    delete ptr;
                    cout<<"\n Data Deleted.";
                }
                else if(ptr->left!=NULL && ptr->right==NULL)
                {
                    cout<<"\n Only Left";
                    if(parent->left==ptr)
                        parent->left=ptr->left;
                    else
                        parent->right=ptr->left;
                    delete ptr;
                    cout<<"\n Data Deleted.";
                }
                else if(ptr->right!=NULL && ptr->left==NULL)
                {
                    cout<<"\n Only Right";
                    if(parent->left==ptr)
                        parent->left=ptr->right;
                    else
                        parent->right=ptr->right;
                    delete ptr;
                    cout<<"\n Data Deleted.";
                }

                else if(ptr->right!=NULL && ptr->left!=NULL)
                    {
                        cout<<"\n Root node:";
                        node *p=ptr->left;
                        parent=NULL;
                        while(p->right!=NULL)
                        {
                            parent=p;
                            p=p->right;
                        }
                        //cout<<p->keyword;
                        strcpy(ptr->keyword,p->keyword);
                        strcpy(ptr->meaning,p->meaning);
                      if(parent!=NULL)
                        parent->right=p->left;
                        delete p;
                        cout<<"\n Data Deleted.";
                    }
                break;
            }
       else
            {
                parent=ptr;
                if(strcmp(ptr->keyword,key)>0)
                    ptr=ptr->left;
                else
                    ptr=ptr->right;
            }
        }
}


int main()
{
    binarytree t;
    node *ptr;
    int ch;
    do
    {
    cout<<"\n\n Binary search Tree Operation:\n\n 1.Create \n 2.Display Tree \n 3.Search the data \n 4.update \n 5.Delete the node \n 6.Reverse\n 7.Exit";
    cin>>ch;
    switch(ch)
    {
    case 1:
        ptr=t.create();
        cout<<"\n Tree is created";
        break;
    case 2:
        cout<<"\n Inorder Traversal";
        t.inorder(ptr);
        break;
    case 3:
        t.search();
        break;
    case 4:
        t.update();
        break;
    case 5:
        t.deletenode();

        break;
    case 6:
    	t.postorder(ptr);
    	break;
    case 7:
        cout<<"\n Exit";
        break;
    default:
        cout<<"Invalid Choice";
        break;
    }
    }while(ch!=6);
    return 0;
}




#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#define false 0
#define true 1
#define ksize 20
#define msize 50
using namespace std;
class node
{
public:
char key[ksize];
char mean[msize];
int bf;
node *left;
node *right;
node()
{
left=NULL;
right=NULL;
}
};
class avltree
{ node *root;
public:
node *insert(node * root,char k[ksize],char m[msize], int *current);
node *create( node * root,char k[ksize],char m[msize],int *current);
void  display(node *root);
node *leftrotation(node *root,int *current);
node *rightrotation(node *root,int *current);
void search(node *root,char *key);
};

node *avltree::insert(node *root,char k[ksize],char m[msize],int *current)
{
avltree t1;
node *create(node *root,char k[ksize],char m[msize],int *current);
root=t1.create(root,k,m,current);
return root;
}
node *avltree::create(node *root,char k[ksize],char m[msize],int *current)
{
node *temp1,*temp2;
if(root==NULL)
{
root=new node();
strcpy(root->key,k);
strcpy(root->mean,m);
root->left=NULL;
root->right=NULL;
root->bf=0;
*current=true;
return (root);
}
if(strcmp(k,root->key)<0)
{
root->left=create(root->left,k,m,current);
//adjusting left subtree
if(*current)
{
switch(root->bf)
{
case 1:temp1=root->left;
if(temp1->bf==1)
{
//LL single rotation
root->left=temp1->right;
temp1->right=root;
root->bf=0;
root=temp1;
}
else
{
//LR rotation
temp2=temp1->right;
temp1->right=temp2->left;
temp2->left=temp1;
root->left=temp2->right;
temp2->right=root;
if(temp2->bf==1)
root->bf=-1;
else
root->bf=0;
if(temp2->bf==-1)
temp1->bf=-1;
else
temp1->bf=0;
root=temp2;
}
root->bf=0;
*current=false;
break;
case 0:
root->bf=1;
break;
case -1:
root->bf=0;
*current=false;
}
}
}
if((strcmp(k,root->key)>0))
{
root->right=create(root->right,k,m,current);
//adjusting the right subtree
if(*current==NULL)
{
 switch(root->bf)
 {
 case 1:
  root->bf=0;
  *current=false;
  break;
  case 0:
  root->bf=-1;
  break;
  case -1:
  temp1=root->right;
  if(temp1->bf==-1)
  {
  //single rotationRR
  root->right=temp1->left;
  temp1->left=root;
  root->bf=0;
  root=temp1;
  }
  else
  {
  //double rotation RL
  temp2=temp1->left;
  temp1->left=temp2->right;
  temp2->right=temp1;
  root->right=temp2->left;
  temp2->left=root;
  if(temp2->bf==-1)
  root->bf=-1;
  else
  root->bf=0;
  if(temp2->bf==1)
  temp1->bf=-1;
  else
  temp1->bf=0;
  root=temp2;
  }//else close
  root->bf=0;
  *current=false;
  }//switch close
}
}

    return(root);
  }
    node *avltree::rightrotation(node *root ,int *current)
    {
    node *temp1,*temp2;
    switch(root->bf)
    {
    case 1:
    root->bf=0;
    break;
    case 0:
    root->bf=-1;
    *current=false;
    break;
    case -1:
    temp1=root->right;
    if(temp1->bf<=0)
    {
    //single rotation RR
    root->right=temp1->left;
    temp1->left=root;
    if(temp1->bf==0)
    {
    root->bf=-1;
    temp1->bf=1;
    *current=false;
    }
    else
    {
    root->bf=temp1->bf=0;
    }
    root=temp1;
    }
    else
    {
    //RL
      temp2=temp1->left;
  temp1->left=temp2->right;
  temp2->right=temp1;
  root->right=temp2->left;
  temp2->left=root;
  if(temp2->bf==-1)
  root->bf=-1;
  else
  root->bf=0;
  if(temp2->bf==1)
  temp1->bf=-1;
  else
  temp1->bf=0;
  root=temp2;
  temp2->bf=0;
  }
  }
  return(root);
  }
 node *avltree::leftrotation(node *root,int *current)
 {
 node * temp1,*temp2;
 switch(root->bf)
 {
 case -1:
 root->bf=0;
 break;
 case 0:
 root->bf=1;
 current=false;
 break;
 case 1:
 temp1=root->left;
 if(temp1->bf>=0)
 {
 //LL
 root->left=temp1->right;
 temp1->right=root;
 if(temp1->bf==0)
 {
 root->bf=1;
 temp1->bf=-1;
 *current=false;
 }
 else
 {
 root->bf=temp1->bf=0;
 }
 root=temp1;
 }
 else
 {
 //lr
 temp2=temp1->right;
temp1->right=temp2->left;
temp2->left=temp1;
root->left=temp2->right;
temp2->right=root;
if(temp2->bf==1)
root->bf=-1;
else
root->bf=0;
if(temp2->bf==-1)
temp1->bf=-1;
else
temp1->bf=0;
root=temp2;
temp2->bf=0;
}
}
return root;
}
void avltree::display(node *root)
{
if(root!=NULL)
{
display(root->left);
cout<<"\n"<<root->key<<":"<<root->mean;
display(root->right);
}
}
void avltree::search(node *root,char *data)
{
node *temp;
temp=root;
int flag;
while(temp!=NULL)
{
if(strcmp(temp->key,data)==0)
{
cout<<"\n meaning"<<temp->mean;
flag=1;
}
if(strcmp(temp->key,data)>0)
temp=temp->left;
else
temp=temp->right;
}
if(flag==0)
{
cout<<"\n key is not in dictionary";
}
}
  int  main()
  {
  node *root=NULL;
  avltree t;
  int current;
  char k[ksize];
  char m[msize];
  char  data[50];
  ifstream myfile;
   myfile.open("/home/dnyaneshwar/Desktop/input1.txt");
  if(myfile==NULL)
  cout<<"\n error" ;
  while(!myfile.eof())
  {
   myfile>>k;
   myfile>>m;
  root=t.insert(root,k,m,&current);
    }
  myfile.close();
  cout<<"\n balanced tree is created";
  t.display(root);
  cout<<"\n enter the keyword  search from dictionary";
  cin>>data;
  t.search(root,data);
  }


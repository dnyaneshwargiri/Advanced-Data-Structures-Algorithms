#include<iostream>
#include<string.h>
using namespace std;

class node
{
	char name[20];
	int init;
	int lineno[20];
	node *next;
public:
	friend class symbol_table;
};
class symbol_table
{
	node *head[20];
	int n;
public:
	symbol_table()
	{
		cout<<"Enter size of hashtable:";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			head[i]=new node;
			head[i]->next=NULL;
			head[i]->init=i;
			head[i]->name[0]='\0';
		}
	}
	int hashfunction(int key);
	void inswthreplace();
	void inswthoutreplace();
	void search();
	void retrieve();
	void modify();
	void delentry();
	void display();
};
int symbol_table::hashfunction(int key)
{
	return key%n;
}
void symbol_table::inswthoutreplace()
{
	int index,key=0,m;
	node *temp,*curr;
	temp=new node;
	temp->next=NULL;
	cout<<"\nEnter identifier: ";
	cin>>temp->name;
	cout<<"Enter identifiers initial value:";
	cin>>temp->init;
	cout<<"Enter number of times it appeared:";
	cin>>m;
	cout<<"Enter line numbers where it appeared:";
	for(int i=0;i<m;i++)
		cin>>temp->lineno[i];
	temp->lineno[m]=-1;
	for(int i=0;temp->name[i]!='\0';i++)
		key=key+int(temp->name[i]);
	index=hashfunction(key);
	curr=head[index];
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=temp;
}
void symbol_table::inswthreplace()
{
	int index,key=0,m;
	node *temp;
	temp=new node;
	cout<<"\nEnter identifier: ";
	cin>>temp->name;
	cout<<"Enter identifiers initial value:";
	cin>>temp->init;
	cout<<"Enter number of times it appeared:";
	cin>>m;
	cout<<"Enter line numbers where it appeared:";
	for(int i=0;i<m;i++)
		cin>>temp->lineno[i];
	temp->lineno[m]=-1;
	for(int i=0;temp->name[i]!='\0';i++)
		key=key+int(temp->name[i]);
	index=hashfunction(key);
	temp->next=head[index]->next;
	head[index]->next=temp;
}
void symbol_table::search()
{
	char temp_name[20];
	int index,key=0;
	node *curr;
	cout<<"\nEnter Identifier to be searched: ";
	cin>>temp_name;
	for(int i=0;temp_name[i]!='\0';i++)
	{
		key=key+int(temp_name[i]);
	}
	index=hashfunction(key);
	curr=head[index]->next;
	while(curr!=NULL)
	{
		if(strcmp(temp_name,curr->name)==0)
			break;
		curr=curr->next;
	}
	if(curr!=NULL)
	{
		cout<<"\nRequested Identifier present.";
	}
	else
	{
		cout<<"\nRequested Identifier not present.";
	}
}
void symbol_table::retrieve()
{
	char temp_name[20];
	int index,key=0;
	node *curr;
	cout<<"\nEnter Identifier whose information is to be retrieved: ";
	cin>>temp_name;
	for(int i=0;temp_name[i]!='\0';i++)
	{
		key=key+int(temp_name[i]);
	}
	index=hashfunction(key);
	curr=head[index]->next;
	while(curr!=NULL)
	{
		if(strcmp(temp_name,curr->name)==0)
			break;
		curr=curr->next;
	}
	if(curr==NULL)
	{
		cout<<"\nRequested Identifier not present.";
	}
	else
	{
		cout<<"Identifier:"<<curr->name<<endl;
		cout<<"Initial value:"<<curr->init<<endl;
		cout<<"Line numbers where Identifier is present:";
		for(int i=0;curr->lineno[i]!=-1;i++)
			cout<<curr->lineno[i]<<",";
	}
}
void symbol_table::modify()
{
	char temp_name[20];
	int index,key=0,ch;
	node *curr;
	cout<<"\nEnter Identifier whose information is to be modified: ";
	cin>>temp_name;
	for(int i=0;temp_name[i]!='\0';i++)
	{
		key=key+int(temp_name[i]);
	}
	index=hashfunction(key);
	curr=head[index]->next;
	while(curr!=NULL)
	{
		if(strcmp(temp_name,curr->name)==0)
			break;
		curr=curr->next;
	}
	if(curr==NULL)
	{
		cout<<"\nRequested Identifier not present.";
	}
	else
	{
		cout<<"Enter serial number of information to be modified.";
		cout<<"\n1)Initial value.";
		cout<<"\n2)Line Number where Identifier occurs.";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"Enter new initial value:";
			cin>>curr->init;
			break;
		case 2:
			int choose,m;
			m=0;
			cout<<"Add new line number or delete a line number?(0/1):";
			cin>>choose;
			if(choose==0)
			{
				while(curr->lineno[m]!=-1)
					m++;
				curr->lineno[m+1]=curr->lineno[m];
				cout<<"Enter new line number:";
				cin>>curr->lineno[m];
			}
			else if(choose==1)
			{
				int linenum;
				cout<<"Enter line number to be deleted:";
				cin>>linenum;
				while(curr->lineno[m]!=linenum && curr->lineno[m]!=-1)
					m++;
				while(curr->lineno[m]!=-1)
				{
					curr->lineno[m]=curr->lineno[m+1];
					m++;
				}
			}
			break;
		default:
			cout<<"Invalid Entry";
			break;
		}
	}
}
void symbol_table::delentry()
{
	char temp_name[20];
	int index,key=0;
	node *curr,*temp;
	cout<<"\nEnter Identifier to be deleted: ";
	cin>>temp_name;
	for(int i=0;temp_name[i]!='\0';i++)
	{
		key=key+int(temp_name[i]);
	}
	index=hashfunction(key);
	temp=head[index];
	curr=head[index]->next;
	while(curr!=NULL)
	{
		if(strcmp(temp_name,curr->name)==0)
			break;
		curr=curr->next;
	}
	if(curr==NULL)
	{
		cout<<"\nRequested Identifier present.";
	}
	else
	{
		temp->next=curr->next;
		delete curr;
	}
}
void symbol_table::display()
{
	int i;
	node *curr;
	cout<<"  Identifier\tInitialization Line numbers \n";
	for(i=0;i<n;i++)
	{
		cout<<i<<endl;
		curr=head[i]->next;
		while(curr!=NULL)
		{
			cout<<" : "<<curr->name<<"\t"<<curr->init<<"\t\t";
			for(int m=0;curr->lineno[m]!=-1;m++)
				cout<<curr->lineno[m]<<",";
			cout<<"\n";
			curr=curr->next;
		}
	}
}
int main()
{
	int choice;
	char again;
	symbol_table table;
	do
	{
		cout<<"\nEnter task number of task you want to perform.";
		cout<<"\n1)Insert with replacement.";
		cout<<"\n2)Insert without replacement.";
		cout<<"\n3)Search for an entry.";
		cout<<"\n4)Retrieve details of a particular entry";
		cout<<"\n5)Modify a particular entry.";
		cout<<"\n6)Delete an entry.";
		cout<<"\n7)Display table.";
		cin>>choice;
		switch(choice)
		{
		case 1:
			table.inswthreplace();
			break;
		case 2:
			table.inswthoutreplace();
			break;
		case 3:
			table.search();
			break;
		case 4:
			table.retrieve();
			break;
		case 5:
			table.modify();
			break;
		case 6:
			table.delentry();
			break;
		case 7:
			table.display();
			break;
		default:
			cout<<"Invalid entry.";
			break;
		}
		cout<<"\nEnter if you want to perform another operation(y/n):";
		cin>>again;
	}while(again=='y'||again=='Y');
	return 0;
}

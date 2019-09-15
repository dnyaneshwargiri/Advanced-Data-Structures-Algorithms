#include <iostream>
#include <fstream>
#include <iomanip>
#include<string.h>
using namespace std;
int i;
class student
{
public:
    string name;
    int roll;
    void getdata()
    {
        cout<<"\n enter name=";
        cin>>name;
       cout<<"\n enter roll no=";
       cin>>roll;
    }
    void display()
    {

        cout<<i+1<<"\t"<<name<<"\t\t"<<roll<<"\n";
    }
};

int main()
{
int pos,rol;
string nam;
int no,loc,ch;
student p[5],q;
fstream file;
file.open("sample.txt",ios::in|ios::out|ios::binary);
if(file.is_open())
cout<<"File opened";
for(i=0;i<3;i++)
{
p[i].getdata();
file.write((char *)&p[i],sizeof(p[i]));
}
file.seekg(0);

cout<<"\n records are=";
cout<<"\nSr.No.\t name\t \tstudent no\n";
for(i=0;i<3;i++)
{
    file.read((char *)&p[i],sizeof(p[i]));
    p[i].display();
}
cout<<"\n1.Determine the student roll of specified person";
cout<<"\n2.Determine the name if student roll number is known";
cout<<"\n3.Update the student roll number, whenever there is a change.";
while(1)
{
cout<<"\n enter your choice=";
cin>>ch;
switch(ch)
{
case 1:

cout<<"\n enter name=";
cin>>nam;
file.seekg(0,ios::beg);
pos=-1;
i=0;
while(!file.eof())
{
    file.read((char*)&p[i],sizeof(p[i]));
    if(nam==p[i].name)
    {
        pos=i;
        break;
    }
    i++;
}
if(pos==-1)
{
cout<<"\n name not found!!";
}
loc=pos*sizeof(p[i]);
file.seekp(loc);
file.read((char*)&p[i],sizeof(p[i]));
cout<<"\n student no.="<<p[i].roll<<"\n";
file.close();
break;

case 2:
    cout<<"\n enter student no.=";
    cin>>rol;
    file.seekg(0,ios::beg);
    pos=-1;
    i=0;
    while(!file.eof())
    {
        file.read((char*)&p[i],sizeof(p[i]));
        if(rol==p[i].roll)
        {
            pos=i;
            break;
        }
        i++;
    }

    loc=pos*sizeof(p[i]);
    file.seekp(loc);
    file.read((char*)&p[i],sizeof(p[i]));
    cout<<"\n name is="<<p[i].name<<"\n";
    file.close();
    break;

case 3:

cout<<"\n enter rollno.to d=";
cin>>no;

int f=0;
   file.seekg(0,ios::beg);
   pos=-1;
   i=0;
   while(!file.eof())
   {
       file.read((char*)&p[i],sizeof(p[i]));
       if(no==p[i].roll)
       {
           pos=i;
           f=1;
           break;

       }
       else
       i++;
   }


if(f==1)
{int l2;
	   l2=pos*sizeof(p[i]);
	  // file.seekp(l2);
	   file.read((char*)&p[i],sizeof(p[i]));
	   cout<<"\n name is="<<p[pos].name<<"\n";

	   while(i<4)
	   {



       file.read((char*)&p[i],sizeof(p[i]));
       file.seekp(l2);
       i++;
	   file.write((char*)&p[i],sizeof(p[i]));
	   l2=l2+sizeof(p[i]);
	   }
	   //file.seekp(loc);
       // p[i].name= "null";
      //  p[i].roll= 1;

        //file.seekp(loc-sizeof(p[i]));
        //p[i].name=NULL;

       // file.write((char*)&q,sizeof(p[i]));
        /*file<<"null";
        		file<<"-1";
	    cout<<"\n del!!";*/

	    file.seekg(0);
	    for(i=0;i<2;i++)
	    {
	        file.read((char *)&p[i],sizeof(p[i]));
	        p[i].display();
	    }
	    file.close();
	    break;
}
else if(f==0)
cout<<"\n  not found!!";
file.close();
break;

}
}
    return 0;
}

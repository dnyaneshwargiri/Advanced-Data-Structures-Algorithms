#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<stack>
using namespace std;

class exp

{public:
	stack < exp *> s;
    char d;
	exp *lc,*rc,*r=NULL;
	exp *cre(char a[])
	{int i=0;
        while(a[i]!='\0')
		{   char c=a[i];
			if(isalpha(c))
			{
			exp *newnode=new exp;
			newnode->d=a[i];
			newnode->lc=NULL;
			newnode->rc=NULL;
			if(r==NULL)
			{ r=newnode;}
			s.push(newnode); //imp
			}
			else{ exp *t1,*t2;
			exp *newnode=new exp;
			newnode->d=a[i];
			t1=s.top();
			s.pop();
			t2=s.top();
			s.pop();
			newnode->lc=t2;
			newnode->rc=t1;
			s.push(newnode);

			}
i++;
		}
		exp *r1=s.top();
		return r1;

	}
	void disp(exp *curr)
	{if(curr!=NULL)
	{disp(curr->lc);
	cout<<"\n"<<curr->d<<"	\n	";
     disp(curr->rc);
	}
	}
};
class convert
{
    public:
	char d[50];
    int top;
    convert()
     {
    	top=-1;
     }
    int empty()
    { if(top==-1)
    	return 1;
      else return 0;
    }
    int full()
    {if(top==49)
    {
    	return 1;
    }
    else return 0;
    }

   void push(char token)
    {
       if(!full())
    {top++;
     d[top]=token;
    }
    else cout<<"\nStack overflow";
    }
     char pop()
    {
        if(empty())
          { cout<<"\nStack Underflow";
          }
        else
        { char z =(d[top]);//important
        top--;
        return (z);
        }


    }
    int priority(char c)
    {
        if(c=='('|| c==')')return 0;
        if(c=='['|| c==']')return 0;
        if(c=='+'|| c=='-')return 2;
        if(c=='*' || c=='/')return 3;
        if(c=='^')     return 4;
    }
    int gettop()
    {
        return top;
    }
    void convertpostfix(char [],char []);
};
void convert::convertpostfix(char in[],char post[])
{
    char a;
    int i=0,j=0;
    char token;
    while(in[i]!='\0')
{
     token=in[i];
    if(token!='+' && token!='-'&&token!='*' && token!='/'&&token!='^'&&token!='('&&token!=')'&&token!='['&&token!=']')
    {
    	post[j]=token;
        j++;
    }
   else
      {
        if(token=='['|| token==']'|| token=='('||token==')'||token=='{'||token=='}' )
          {
            if(token=='['  )
          {
           push(token);
          }
        else if(token==']')
          {   a=pop();
        	 while(a!='[')
                { post[j]=a;
                  j++;
                  a=pop();
                }
           }

        else if(token=='('  )
             {
              push(token);
             }


        else if(token==')')

        {    a=pop();
        	while(a!='(' )
            {
            post[j]=a;
            j++;
            a=pop();
            }
        }
   }
       else if(token=='+'||token=='-'||token=='*'||token=='^'||token=='/')
       {   if (priority(token)<=priority(d[top])&&!empty())
           {
            a=pop();
            post[j]=a;
            j++;
            push(token);
           }
          else
         {push(token);
         }
      }

   }
    i++;
}
    while(!empty())
    {
        a=pop();
        post[j]=a;
        j++;
    }
    post[j]='\0';

}
int main()
{exp e,e2,*r2;
convert p;
  char in[50],post[50];
  cout<<"\nEnter expression";
  cin>>in;
  cout<<in;
  p.convertpostfix(in,post);
  cout<<"\nPostfix expression\n";
  cout<<post;
  r2=e.cre(post);
  cout<<"\nInordred Traversssal \n";
  e2.disp(r2);

  return 0;
}

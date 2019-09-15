
#include <iostream>
using namespace std;
class Hashing
{public :
    long  int a[10],key[10],chain[10],i,j,k,n;
    long  int * accept();
    void display(long int *);
    long  int *HashingWithChain(long int *);

};
long int * Hashing::accept()
{
    cout<<"Enter the size of hash table" ;
    cin>>n;
    for (i = 0; i < n; i++)
    {
        cout<<"\nEnter element no "<<i<<" ";
        cin>>a[i];
        key[i]=-1;
        chain[i]=-1;
    }

return a;
}
 void Hashing::display(long int *a)
 {
     cout<<"\nKey  :     value  :     chain:";
     for (i = 0; i < n;i++)
     {
     cout<<"\n"<<i<<"     "<<a[i]<<"   "<<chain[i];
     }

 }
 long int * Hashing::HashingWithChain(long int *a)
 {
     for (i = 0; i < n;i++)
     {
           j=a[i] % n;
           k=j;
           if(key[j]==-1)
           { key[j]=a[i];  }
           else
              {
               while(key[j]!=-1)
        {
            //loop:

          if(j==(n-1))
            { j=0;}
         else j++;
        }
         key[j]=a[i];
         if(chain[k]==-1)
         { chain[k]=j;     }
        else
        {
         while(chain[k]!=-1)
          {
         k=chain[k];
          }
         chain[k]=j;
        }
      }

     }
return key;

 }

int main()
{long int *b,*c;
Hashing h;
b=h.accept();
c=h.HashingWithChain(b);
h.display(c);
return 0;
}

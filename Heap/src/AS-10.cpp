
#include <iostream>
using namespace std;

class heap
{
public:
    int keymax[10],keymin[10],newkey,i;
    heap()
    {
        for(i=0;i<10;i++)
        {
            keymax[i]=0;
            keymin[i]=0;
        }
    }
    void heapmax(int i);
    void heapmin(int i);
};
void heap::heapmax(int i)
{
int s,parent,temp;
s=i;
parent=(s-1)/2;
keymax[s]=newkey;

while(s>0 && keymax[parent]<=keymax[s])
{
    temp=keymax[parent];
    keymax[parent]=keymax[s];
    keymax[s]=temp;
    s=parent;
    parent=(s-1)/2;
}
}
void heap::heapmin(int i)
{
    int s,parent,temp;
    s=i;
    parent=(s-1)/2;
    keymin[s]=newkey;

    while(s>0 && keymin[parent]>=keymin[s])
    {
        temp=keymin[parent];
        keymin[parent]=keymin[s];
        keymin[s]=temp;
        s=parent;
        parent=(s-1)/2;
    }
}
int main()
{
    heap s;
    int n,i;
    cout<<"\n ENter No. of key to be enter=";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"\n ENter key=";
        cin>>s.newkey;
        s.heapmax(i);
        s.heapmin(i);
    }
    cout<<"\n MAX=";
    cout<<s.keymax[0]<<"\t";
    cout<<"\n\n";
    cout<<"\n MIN=";
    cout<<s.keymin[0]<<"\t";


    return 0;
}



#include<iostream>
#include<stack>
using namespace std;
class mst
{
    int n,i,j;

    int cost[10][10],v[10];
public:
    void accept();
    void dfs(int node);
    void nrdfs(int node);
    void print();

};
void mst::accept()
{

    cout<<"\nEnter the number of cities:";

    cin>>n;

    cout<<"\nEnter the adjacency matrix:\n";

    for(i=1;i<=n;i++)
    {v[i]=0;

        for(j=1;j<=n;j++)

        {

            cin>>cost[i][j];


        }
    }
}
void mst::print()
{
    cout<<"\nAdjacency matrix is :\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)

        {

        cout<<"cost: city "<<i<< "to "<<j<<"= "<<cost[i][j]<<"\t";


        }
    cout<<"\n";
    }

}
void mst::dfs(int node)
{  int i,j;
	v[node]=1;
	cout<<"\n"<<node;
	for(i=1;i<=n;i++)
	{
		if(cost[node][i]==1)
		{
		if(!v[i])
			dfs(i);
		}
	}
}
void mst::nrdfs(int node)
{   stack<int > s;

	s.push(node);
	while(!s.empty())
	{

		i=s.top();
				s.pop();
		if(!v[i])
		{  cout<<"\n"<<i;
	     	v[i]=1;
			for(j=n;j>=1;j--)   //imp
			{
				if(cost[i][j]==1)    //imp
				{
				if(!v[j])
				s.push(j);     //imp
				}
			}
		}

	}
}

int main()
{
    mst m;
    m.accept();
    m.print();
  //  m.dfs(1);
    m.nrdfs(1);
}


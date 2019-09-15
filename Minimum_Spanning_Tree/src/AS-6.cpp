
#include<iostream>
using namespace std;
class mst
{
    int a,b,u,v,n,i,j,ne=1;

    int visited[10]={0},min,mincost=0,cost[10][10];
public:
    void accept();
    void print();
    void cal();
};
void mst::accept()
{

    cout<<"\nEnter the number of cities:";

    cin>>n;

    cout<<"\nEnter the adjacency matrix:\n";

    for(i=1;i<=n;i++)
    {

        for(j=1;j<=n;j++)

        {

            cin>>cost[i][j];

            if(cost[i][j]==0)

            cost[i][j]=999;
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

        cout<<cost[i][j]<<"\t";


        }
    cout<<"\n";
    }

}
void mst::cal()
{
    visited[1]=1;

        cout<<"\n";

        while(ne < n)

        {

            for(i=1,min=999;i<=n;i++)
            {

                for(j=1;j<=n;j++)
                {
                    if(cost[i][j]< min)
                    {
                        if(visited[i]!=0)

                        {

                            min=cost[i][j];
                            a=u=i;
                            b=v=j;

                        }
                    }
                }
            }

            if(visited[u]==0 || visited[v]==0)

            {

                cout<<"\n Edge No "<<ne++<<":("<<a<<" to "<<b<<") cost is :"<<min;

                mincost+=min;

                visited[b]=1;

            }

            cost[a][b]=cost[b][a]=999;

        }

        cout<<"\n Minimum cost="<<mincost;

}
int main()
{
    mst m;
    m.accept();
    m.print();
    m.cal();
}


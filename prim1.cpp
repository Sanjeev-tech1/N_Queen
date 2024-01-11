#include<iostream>
#include<stdlib.h>
#include<conio.h>
#define INFINITY 999

using namespace std;

int  main()
{
    int a,b,u,v,n,i,j,ne=1;
    int visited[10]={10},cost[10][10];
    int min,mincost=0;

    cout<<"\n prime algo Implementation \n";
    cout<<"\n Enter the number of nodes:";
    cin>>n;
    cout<<"\n Enter Costs for NODES :\n";

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<"Cost->Node["<<i<<"] to Node["<<j<<"]:";
            cin>>cost[i][j];
            if(cost[i][j]==0)
            cost[i][j]=INFINITY;
        }
        cout<<endl;
    }
    visited[1]=1;
    cout<<endl;

    while(ne<n)
    {
        for(i=1,min=INFINITY;i<=n;i++)
        for(j=1;j<=n;j++)
        if(cost[i][j]<min)
        if(visited[i]!=0)
        {
            min=cost[i][j];
            a=u=i;
            b=v=j;
        }
        if(visited[u]==0|| visited[v]==0)
        {
            cout<<"\n Edge "<<(ne++);
            cout<<"("<<a<<" "<<b<<")cost:"<<min;
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=INFINITY;
    }
    cout<<"\n Minimun Cost of Spanning tree="<<mincost;
    getch();
    return 0;
}
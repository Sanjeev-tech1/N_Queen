#include<stdio.h>

#define V 4

#define INF 999

void printfSolution(int dist[][V]);

void floydwarshall(int dist[][V])
{
    int i,j,k;

    for(k=0;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
              if(dist[i][k]+dist[k][j]<dist[i][j])  
              dist[i][j]=dist[i][k]+dist[k][i];
            }
        }
    }
    printfSolution((dist));
}
void printfSolution(int dist[][V])
{
    printf(" the following matrix  show the shortest distance between every pair of vertices \n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]==INF)
            printf("%7s","INF");
            else
            printf("%7d",dist[i][j]);
        }
        printf("\n");
    }

}
int main(){
    int graph[V][V]={{0,5,INF,10},
                     {INF,0,3,INF},
                     {INF,INF,0,1},
                     {INF,INF,INF,0}};
                     floydwarshall(graph);
                     return 0;
}

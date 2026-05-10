#include<iostream>
#include<vector>
using namespace std;

bool goodcolor(vector<int>adj[],vector<int>col){
    for(int i=0;i<col.size();i++){
        for(auto it:adj[i]){
            if(i!=it &&col[i]==col[it])
            return false;
        }
    }
    return true;
}


bool generatecolor(int i,vector<int>col,int m,vector<int>adj[]){
    if(i>=col.size()){
        if(goodcolor(adj,col))
        return true;

        return false;
    }

    for(int j=0;j<m;j++){
        col[i]=j;
        if(generatecolor(i+1,col,m,adj))
        return true;
        col[i]=-1;
    }
    return false;
}


bool graphColoring(int v,vector<vector<int>>&edges,int m){
    vector<int>adj[v];

    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int>color(v,-1);
    return generatecolor(0,color,m,adj);
}

int main(){
    int V=4;
    vector<vector<int>>edge={
        {0,1},
        {0,2},
        {0,3},
        {1,3},
        {2,3}
    };
    int m=3;
    cout<<(graphColoring(V,edge,m)?"true":"false")<<endl;
}
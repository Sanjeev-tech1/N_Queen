#include<bits/stdc++.h>
#include<vector>
using namespace std;

void dfs(vector<vector<int>> &img,int x,int y,int oldcolor,int newColor){
    if(x<0 ||x>=img.size()|| y<0 || y>=img[0].size()|| img[x][y]!=oldcolor){
        return;
    }

    img[x][y]=newColor;
    dfs(img,x+1,y,oldcolor,newColor);
    dfs(img,x-1,y,oldcolor,newColor);
    dfs(img,x,y-1,oldcolor,newColor);
    dfs(img,x,y+1,oldcolor,newColor);
}


vector<vector<int>>floodFill(vector<vector<int>>&img, int sr,int sc,int newColor){


    if(img[sr][sc]==newColor){
        return img;
    }
    int oldColor=img[sr][sc];
    dfs(img,sr,sc,oldColor,newColor);

    return img;
}
  
int main () {
    vector<vector<int>>img={
        {1,1,1,0},
        {0,1,1,1},
        {1,0,1,1}
    };

    int sr=1,sc=2;
    int newColor=2;

    vector<vector<int>>result=floodFill(img,sr,sc,newColor);

    for(auto & row:result){
        for(auto &pixel: row){
            cout<<pixel<<" ";
        }
        cout<<"\n";
    }
  
  
return 0;
}
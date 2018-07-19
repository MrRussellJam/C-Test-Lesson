#include <iostream>
#include <string.h>

using namespace std;

char map[20][20];
int dis[20][20];
int sum;
int n,m;

int road[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};


void dfs(int y,int x){
    int  k=0;
    int i,j;
    for(k=0;k<4;k++){
        i=y+road[k][0];
        j=x+road[k][1];
        if(i >= 0 && i < m && j >= 0 && j < n && dis[i][j]!=-1 && dis[i][j]!=1){
            sum++;
            dis[i][j]=1;
            dfs(i,j);
        }
    }
}

int main(){
    while(1){
        cin>>n>>m;
        memset(map,0,sizeof(map));
        memset(dis,0,sizeof(dis));
        if(n==0&&m==0) break;
        int x,y;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                cin>>map[i][j];
                if(map[i][j]=='@'){
                    y=i;x=j;
                }
                if(map[i][j]=='#') dis[i][j]=-1;
            }
        sum=0;
        dfs(y,x);
        cout<<sum<<endl;
    }

    return 0;
}
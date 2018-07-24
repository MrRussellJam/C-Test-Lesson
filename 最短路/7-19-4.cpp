#include <iostream>
#include <string.h>
using namespace std;

int edge[1000][1000];
int dis[1000][1000];
int n,m;
const int INF = -10000;

int main(){
    cin >> n >> m ;
    memset(edge,0,sizeof(edge));
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        edge[a][b] = 1;
    }

    for(int k = 0;k < n;k++){
        for(int i = 0 ;i < n;i++){
            for(int j = 0 ; j < n; j++){
                if( edge[i][j] < edge[i][k] + edge[k][j] ) edge[i][j] = 1;
                else if( !edge[j][i] ) 
            }
        }
    }
    return 0;
}
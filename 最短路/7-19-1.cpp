#include <iostream>
#include <queue> 
#include <string.h>

using namespace std;

int dist[1000][1000];
int cont[1000][1000];
int n,m;
int INF = 9999;

// int dijkstra(int st){
//     for(int i = 0;i <= n;i++)
// }

int main(){
    cin >> n >> m;
    int a,b,c;
    memset(cont,INF,sizeof(cont));
    for( int i = 0; i < n; i++ ){
        cin >> a >> b >> c;
        cont[a][b] = c;
    }

    for( int i = 0;i <= n; i++ ){
        for(int j = 0;j <= n;j++){
            dist[i][j] = cont[i][j];
        }
    }

    for( int k = 0;k <= n; k++ ){
        for( int i = 0;i <= n; i++ )
            for( int j = 0;j < n; j++ ){
                if( dist[i][k] + dist[k][j] < dist[i][j]){
                   dist[i][j] = dist[i][k] + dist[k][j]; 
                }
            }
    }

    cout << dist[1][5];

    return 0;
}
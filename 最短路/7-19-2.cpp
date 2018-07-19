#include <iostream>
#include <string.h>

using namespace std;

int count[1000][1000];
bool vis[1000];
int dist[1000];
int MAXN = 9999;
int n,m;


int dijkstra(int sta){
    for(int i = 0; i < n;i++){
        vis[i] = false;
        dist[i] = count[sta][i]; 
    }
    dist[sta] = 0;
    vis[sta] = true;
    for(int i = 0; i < n ; i++){
        int temp = MAXN;
        int k = -1;
        for(int j = 0 ; j < n;j++){
            if(!vis[j] && temp > dist[j] ){
                temp = dist[j];
                k = j;
            }
        }
        if( k == -1 ) break;
        vis[k] = true;
        for( int j = 0; j < n ; j++ ){
            if( !vis[j] && dist[j] > dist[k] + count[k][j] ){
                dist[j] = dist[k] + count[k][j];
            }
        }
    }
    return dist[m - 1];
}

int main(){
    int a,b,c;
    cin >> n >> m;
    memset(count,MAXN,sizeof(count));
    memset(vis,false,sizeof(vis));
    for(int i = 0; i < n; i++ ){
        cin >> a >> b >> c ;
        a = a - 1;
        b = b - 1;
        count[a][b] = c;
        count[b][a] = c;
    }
    int sum;

    sum = dijkstra(0);
    cout << sum << endl;
    return 0;
}

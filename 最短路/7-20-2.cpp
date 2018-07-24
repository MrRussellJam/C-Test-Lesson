#include <iostream>
#include <string.h> 

using namespace std;


int dis[101];
int n,m;
int vis[101];
int INF = 100000000;
int map[101][101];

void Dijkstra(){
    for( int i = 0 ; i < n ; i++ ){
        vis[i] = 0;
        dis[i] = map[0][i];
    }

    dis[0] = 0;
    vis[0] = 1;

    while(1){
        int temp = INF ;
        int k = -1;
        for( int i = 0 ; i < n ; i++ ){
            if( !vis[i] && temp > dis[i] ){
                temp = dis[i];
                k = i;
            cout << "here" << endl;
            }
        }
        if(k == -1) break;
        vis[k] = 1;
        for( int i = 0; i < n ; i++ ){
            if( !vis[i] && dis[i] > dis[k] + map[k][i] ){
                dis[i] = dis[k] + map[k][i];
            }
        }
    }
}

int main(){
    while(1){
        cin >> n >> m ;
        if( n == 0 && m == 0 ) break;
        int a,b,c;
        memset(map,INF,sizeof(map));
        for( int i = 0 ; i < m ; i++ ) {
            cin >> a >> b >> c;
            map[a-1][b-1] = c;
            map[b-1][a-1] = c;
        }

        Dijkstra();

        cout << dis[n - 1] << endl;
    }

    return 0;
}
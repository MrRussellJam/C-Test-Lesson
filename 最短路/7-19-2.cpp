#include <iostream>
#include <string.h> 

using namespace std;



int dis[2005];
int n,m;
int vis[2005];
int INF = 1000000;
int map[2005][2005];

void Dijkstra(){
    for( int i = 1 ; i <= n ; i++ ){
        vis[i] = 0;
        dis[i] = map[1][i];
    }

    dis[1] = 0;
    vis[1] = 1;

    for( int j = 1; j <= n ; j++ ){
        int temp = INF ;
        int k = -1;
        for( int i = 1 ; i <= n ; i++ ){
            if( !vis[i] && temp > dis[i] ){
                temp = dis[i];
                k = i;
            }
        }
        if(k == -1) break;
        vis[k] = 1;
        for( int i = 1; i <= n ; i++ ){
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
        for(int i = 1; i <= n; i++) map[i][i] = 0;
        for( int i = 1 ; i <= m ; i++ ) {
            cin >> a >> b >> c;
            if(c < map [a][b]) {
	            map[a][b] = c;
	            map[b][a] = c;
			}
        }

        Dijkstra();

        cout << dis[n] << endl;
    }

    return 0;
}
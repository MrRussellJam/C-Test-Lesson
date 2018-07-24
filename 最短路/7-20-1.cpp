#include <iostream>
#include <string.h>

using namespace std;

int n,m;
int u[1001],v[1001],w[1001];
int dis[1001];
const int INF = 9999;

void BellmamFlord(){
    bool used = true;
    while( used ){
        used = false;

        for( int i = n ; i > 0 ; i-- ){
            if(dis[u[i]] > dis[v[i]] + w[i] ) {
                dis[u[i]] = dis[v[i]] + w[i] ;
                used = true;
            }
            else if(dis[v[i]] > dis[u[i]] + w[i] ){
                dis[v[i]] = dis[u[i]] + w[i] ;
                used = true;
            }
        }

    }

}

int main(){
    while(1){
        cin >> n >> m;
        if( n == 0 && m == 0 )  break;

        for( int i = 1 ; i <= m ; i++ ) cin >> u[i] >> v[i] >> w[i] ;
        memset( dis , INF , sizeof(dis) );
       
        dis[n] = 0;
        BellmamFlord();

        cout << dis[1] << endl;
    }

    return 0;
}
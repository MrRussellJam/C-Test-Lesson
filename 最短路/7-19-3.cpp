#include <iostream>
#include <string.h>

using namespace std;

int n,m;
const int p = 1005;
int u[p];
int v[p];
int w[p];
int dis[p];
int dis2[p];
int INF = 9999;

void BellmanFloyd(int sta){
    for(int i = 1;i<=n - 1;i++){
        int check = 0;
        for(int j = 1;j < n;j++){
            if(dis[v[j]] > dis[u[j]] + w[j] ){
                dis[v[j]] = dis[u[j]] + w[j];
                check = 1;
            }
        }
        if(check == 0 ) break;
    }
}

void BellmanFloyd2(int sta){
    for(int i = 1;i<=n - 1;i++){
        int check = 0;
        for(int j = 1;j < n;j++){
            if(dis2[u[j]] > dis2[v[j]] + w[j] ){
                dis2[u[j]] = dis2[v[j]] + w[j];
                check = 1;
            }
        }
        if(check == 0 ) break;
    }
}


int main(){
    while(scanf("%d%d",&n,&m) != EOF){
        memset(dis,INF,sizeof(dis));
        memset(dis2,INF,sizeof(dis2));
        for(int i = 1 ; i <= n ; i++ ){
            cin >> u[i] >> v[i] >>w[i];
        }

        dis[1] = 0;
        BellmanFloyd(1);
        BellmanFloyd2(1);
        
        int t = 0;
        if( dis[m] > dis2[m] ) cout << dis2[m] << endl;
        else cout << dis[m] <<endl;
    }
    return 0;
}
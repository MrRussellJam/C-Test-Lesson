#include <iostream>
#include <queue>
#include <string.h>
#include <functional>

using namespace std;


int INF = 1000000;
int n,m;
int dis[1001];
int vis[1001];
int map[1001][1001];
typedef struct Deps{
    int d;
    int p;
}dep[1001][1001],dis[1001];

priority_queue<int > q;

void spfa(int x){
    dis[x] = 0;
    q.push(x);
    while(!q.empty()){
        int y = q.front();
        for(int i = 1; i <= n ; i++ ){
            if(dis[i].d >= dis[y].d + dep[y][i].d ){
                dis[i].d = dis[y].d + dep[y][i].d;
                if(dis[i].p > dis[y].p + dis[y][i].p ){
                    dis[i].p = dis[y].p + dis[y][i].p;
                }
                q.push(i);
            }
        }
        q.pop();
    }

}

int main(){
    cin >> n >> m ;
    if( n == 0 && m == 0 ) break;
    int a,b,d,p;
    memset(dep,INF,(sizeof(dep))*1001);
    memset(vis,0,sizeof(vis));
    memset(dis,INF,(sizeof(dis))*1001);
    for(int i = 0; i < m;i++){
        cin >> a >> b >> d >> p;
        dep[a][b].d = d;
        dep[b][a].p = p;
    }
    int from ,end;
    cin >> from >> end;
    spfa(from);
    cout << dis[end].d << " " << dis[end].p << endl ;
    return 0;
}
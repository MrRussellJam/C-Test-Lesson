#include <iostream>
#include <string.h>

using namespace std;

int dir[4][2] = { { 1 , 0 } , { -1 , 0  } , { 0 , 1 } , { 0 , -1 } };
char map[10][10];
int vis[10][10];
int time;
int t;
int n;

void dfs(int x ,int y){
    if(map[x][y] == 'D') {
        if(t > n) t = n; 
        return ;
    }
        cout << "out" << endl;
    if( vis[x][y] || map[x][y] == 'X') return ;
    vis[x][y] = 1;
    for(int i = 0 ;i < 4;i++){
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        n++;
        dfs(tx,ty);
        n--;
    }
    return ;
}


int main(){
    int a,b;
    while(scanf("%d%d%d" ,&a,&b,&time) && a != 0 && b != 0 && time != 0 ){
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        int x,y;
        t = 9999;
        n = 0;
        for(int i = 1; i <= a ; i++ ){
            cin >> map[i];
            for(int j = 1; j <= b ; j++ ){
                if(map[i][j] == 'S') {
                    x = i; y = j;
                }
            }
        }
        dfs(x,y);
        if( t == time ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
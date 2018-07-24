#include <iostream>
#include <string.h>

using namespace std;

int vis[1001][1001];
char map[1001];
int dir[4][2] = { { 1 , 0 } , { -1 , 0 } , { 0 , 1 } , { 0 , -1 } };

int n,m;


int main(){
    int T;
    cin >> T;
    memset(vis,0,sizeof(vis));
    while( T-- ){
        cin >> n >> m;
        for(int i = 0; i < n ;i++){
            cin >> map[i];
            for(int j = 0;j < m ;j++){
                if(map[i][j] == '*') vis[i][j] = 1;
            }
        }

    }
    return 0;
}
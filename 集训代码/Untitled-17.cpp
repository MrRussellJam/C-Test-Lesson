#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

char map[101][101];
bool dis[101][101];
int dir[4][2] = { { -1 , 0 } , { 1 , 0 } , { 0 , -1 } , { 0 , 1 } };
int n,m;
struct dep{
    int x;
    int y;
    int sum;
};

int main(){
    while( scanf("%d%d",&n,&m) != EOF ){
        struct dep deps[100];
        memset(map,0,sizeof(map));
        memset(dis,true,sizeof(dis));
        queue<dep> q;
        for(int i = 0; i < n ;i++){
            cin >> map[i];
            for(int j = 0; j < n ; j++){
                if(map[i][j] == '#' ) dis[i][j] = false;
            }
        }

        while( !q.empty() )
    }

    return 0;
}
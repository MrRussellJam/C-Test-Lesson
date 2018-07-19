#include <iostream>
#include <string.h>

using namespace std;

char map[101][101];
bool dis[101][101];
int dir[4][2] = { { -1 , 0 } , { 1 , 0 } , { 0 , 1 } , { 0 , -1 } };
int n,m;


int main(){
    cin >> n >> m;
    memset(map,0,sizeof(map));
    memset(dir,0,sizeof(dir));
    for(int i = 0;i < n;i++){
        cin >> map[i];
        for(int j = 0;j < n;j++){
            if(map[i][j] == '#') dir[i][j] = false;
        }
    }
    
    return 0;
}
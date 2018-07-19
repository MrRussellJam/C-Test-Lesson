#include <iostream>
#include <string.h>
using namespace std;

char sheep[101][101];
bool isSheep[101][101];
int dir[4][2] = { {-1,0} , {1,0} , {0,-1} , {0,1} };
int sum;
int lokx,loky;
bool isSon;
int n,m;


void dfs(int x,int y){
	
    if(!isSheep[x][y]) return;

    if(!isSon){
        sum++;
    }
    isSon = true;
    isSheep[x][y] = false;

    int xx,yy;
    for(int i=0;i<4;i++){
        xx = x + dir[i][0];
        yy = y + dir[i][1];

        if( xx >= 0 && xx < n && yy >= 0 && yy < m ){
            dfs(xx,yy);
        }else{
            continue;
        }
    }

    return;
}


int main(){
    int T;
    cin>>T;
    while(T--){
        cin >> n >> m;
        isSon = false;
        sum = 0;
        memset(sheep,0,sizeof(sheep));
        memset(isSheep,true,sizeof(isSheep));
        char grass = '.';
        for(int i = 0;i < n; i++ ){
            cin >> sheep[i];
            for(int j = 0;j < m; j++ ){
                if(sheep[i][j] == grass){
                    isSheep[i][j] = false;
                }
            }
        }

        for(lokx = 0;lokx < n; lokx++ )
            for(loky = 0;loky < m ; loky++ ){
                dfs(lokx,loky);
                isSon = false;    
            }
        cout << sum << endl;

    }
    return 0;
}
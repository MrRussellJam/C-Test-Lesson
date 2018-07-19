#include <iostream>
#include <string.h>

using namespace std;

char map[101][101];
bool dis[101][101];
int dir[4][2] = { {-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1} };
int sum,time;
int mintime = 9999999;
int n,m;
int x,y;
bool print;


void dfs(int x,int y){
	
    if(!dis[x][y]) return ;
    
    
    if(map[x][y] == 'r' ){
        if(mintime > time) {
            mintime = time;
            return;
        }else {
            return;
        }
    }

    int xx,yy;
    for(int i = 0;i < 4;i++){
        xx = x + dir[i][0];
        yy = y + dir[i][1];
        if(xx >= 0 && xx < n && yy >= 0 && yy < m){
            if( map[xx][yy] == 'x' ){
                time = time + 2;
    			dis[x][y] = false;
                dfs(xx,yy);
    			dis[x][y] = true;
                time = time - 2;
            }else if(map[xx][yy] == 'r' || dis[xx][yy]){
                time ++;
    			dis[x][y] = false;
                dfs(xx,yy);
    			dis[x][y] = true;
                time --;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    memset(dis,true,sizeof(dis));
    memset(map,0,sizeof(map));
    print = false;
    for(int i = 0 ;i < n;i++){
        cin >> map[i];
        for(int j = 0; j < m;j++){
            if(map[i][j] == '#' ) dis[i][j] = false;
            if(map[i][j] == 'a' ){
            	x = i;
				y = j;
			}
        }
    }
    time = 0;
    dfs(x,y);
    if(mintime != 9999999){
        cout << mintime << endl;
    }else {
        cout << "Poor ANGEL has to stay in the prison all his life." << endl;
    }
    return 0;
}
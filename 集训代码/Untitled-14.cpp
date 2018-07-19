#include <iostream>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;
int map[6][6];
bool dis[6][6];
int dir[4][2] = { { 1 , 0 } , { -1 , 0 } , { 0 , -1 } ,{ 0 , 1 } };
struct Deps{
    int x;
    int y;
}dep[100];
queue<Deps> q;
stack<Deps> s;

int main(){
    memset( map , 0 , sizeof(map) );
    memset( dis , true , sizeof(dis) );
	for(int i = 0;i < 5; i++){
		cin >> map[i];
		for(int j = 0; j < 5;j++){
			if(map[i][j]) dis[i][j] = false;
		}
	}
	Deps now;
    Deps next;
    now.x = 0;
    now.y = 0;
    q.push(t);

    while( !q.empty() ){
        now = q.front();
        q.pop();
        for(int i = 0;i < 4; i++){
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];
            if(next.x >= 0 && next.x < n && next.y >= 0 && next.y <m ){
                if( dir[next.x][next.y] ){
                    q.push(next);
                    dir[next.x][next.y] = false;
                }
            }
        }
    }

    return 0;
}
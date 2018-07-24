#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n,m;
int dir[4][2] = { { 1 , 0 } , { -1 , 0 } , { 0 , 1 } , { 0 , -1 } };
int vis[1001][1001];
char map[1001][1001];
int x,y;
struct Dep{
    int x;
    int y;
    int sum;
}deps[1001];

int bfs(){
    queue<Dep> q;
    struct Dep d;
    d.x = x;
    d.y = y;
    d.sum = 0;
    q.push(d);
    int t = 10000;
    int temp = 10000;
    while(!q.empty()){
        d = q.front();
        q.pop();
        int xx,yy;
        for(int i = 0;i < 4;i++){
            xx = d.x + dir[i][0];
            yy = d.y + dir[i][1];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy] ){
                vis[xx][yy] = 1;
                struct Dep td;
                td.x = xx ;
                td.y = yy ;
                if(map[xx][yy] == 'x') td.sum = d.sum + 2 ;
                else td.sum = d.sum++ ;
                if(map[xx][yy] == 'r' ) {
                    vis[xx][yy] = 0 ;
                    temp = td.sum ;
                    if(t > temp) t = temp ;
                }
                q.push(td);
            }
        }
    }
    return t;
}

int main(){
    while( scanf("%d%d",&n,&m) != EOF ){
        x = 0;
        y = 0;
        for( int i = 0 ; i < n ; i++){
            cin >> map[i];
            for( int j = 0 ; j < m ; j++ ){
                if(map[i][j] == '#' ) {
                    cout << "here" << endl;
                    vis[i][j] = 1;
                }
                if(map[i][j] == 'a' ){
                    x = i;y = j;
                }
            }
        }

        int sum = bfs();

        cout << sum << endl;
    }

    return 0;
}
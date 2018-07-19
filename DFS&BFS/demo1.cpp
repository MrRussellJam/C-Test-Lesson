#include <iostream>
#include <string.h>

using namespace std;

char map[101][101];
int oil[101][101];
int sum;
int n,m;
int head,tail;
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
bool isSon;

struct Queue{
    int x;
    int y;
    int team;
}queue[101];

void dfs(int x,int y){
    int k;
    int i,j;
    if(oil[x][y] == -1) {
        if(y == m-1) dfs(x+1,0);
        else dfs(x,y+1);
        return ;
    }

    for(k=0;k<8;k++){
        i = x + dir[k][0];
        j = y + dir[k][1];
        if( i < 0 || i >= n || j < 0 || j >= m || oil[i][j] == 1 || oil[i][j] == -1 ) 
            continue;
        else{
            if(head == tail){
                queue[tail].x = x;
                queue[tail].y = y;
                queue[tail].team = 1;
                tail++;
                oil[i][j] == 1;
            }else if(isSon){
                queue[tail].x = x;
                queue[tail].y = y;
                queue[tail].team = queue[tail-1].team;
                tail++;
                oil[i][j] == 1;
            }else{
                queue[tail].x = x;
                queue[tail].y = y;
                queue[tail].team = queue[tail-1].team + 1;
                tail++;
                oil[i][j] == 1;
            }
        }
        isSon = true;
        dfs(i,j);
    }
    isSon = false;
}

int main(){
    while(1){
        head = 0;
        tail = 0;
        cin >> n >> m;
        isSon = false;
        if(n == 0 && m == 0) break;
        memset(map,0,sizeof(map));
        memset(oil,0,sizeof(oil));
        memset(queue,0,sizeof(queue));
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++){
                cin >> map[i][j];
                if(map[i][j] == '*') oil[i][j] == -1;
            }
        sum = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                dfs(i,j);
        if(tail==0)  cout << queue[tail].team << endl;
        else  cout << queue[tail - 1].team << endl;
    }

    return 0;
}
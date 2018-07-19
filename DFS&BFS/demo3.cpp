#include <iostream>
#include <string.h>
#include <string>

using namespace std;

char map[101][101];
bool oil[101][101];
int dir[8][2]={{-1,0},{-1,-1},{-1,1},{0,-1},{0,1},{1,0},{1,-1},{1,1}};
int n,m;
bool isSon;
int sum;

void dfs(int x,int y){

    if(!oil[x][y]) {
//    	cout<<x<<"<x,y>"<<y<<endl;
    	return;
	}
    if(!isSon){
    	sum++;
	}
    isSon = true;
    oil[x][y] = false;

    int xx,yy;
    int k = 0;
    for(k;k<8;k++){
        xx = x + dir[k][0];
        yy = y + dir[k][1];
        if(xx >= 0 && xx < n && yy >=0 && yy < m){
            dfs(xx,yy);
        }else{
            continue;
        }
    }
    return;
}


int main(int argc, char const *argv[]){
    while(1){
    	//初始化 
        isSon = false;
        sum = 0;
        char nooil = '*';
        cin >> n >> m;
        if(n == 0 && m == 0)  break;
        memset(map,0,sizeof(map));
        memset(oil,true,sizeof(oil));

        // 读取一行字符 在判断每个字符是否为oil
        for(int i = 0;i < n;i++){
            cin >> map[i];
            for(int j = 0;j < m;j++){
                if(map[i][j] == nooil) {
                	oil[i][j] = false;
				}
            }
        }
        

        // 对 为oil的坐标 进行深搜 
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
		// cout<<1<<endl;
                dfs(i,j);
                isSon = false;
            }
        }
        cout<<sum<<endl;//todo cout the final sum

    }
    return 0;
}


#include <iostream>
#include <string.h>

using namespace std;

int n,m;
int link[1000][1000];
int girl;
bool used[1000];

bool cut(int u){
    for(int i = 1; i <= n;i++){
        if(!used[i] && link[u][i]){
            used[i] = true;
            if(girl[i] == 0 || cut(girl[i])){
                girl[u] = u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    
    memset(girl,0,sizeof(girl));
    memset(link,0,sizeof(link));
    memset(used,false,sizeof(used));
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        link[a][b] = 1;
    }
    int sum = 0;
    for(int i = 1; i <= n ;i++){
        memset(used,0,sizeof(used));
        if(cut(i)){
            sum++;
        }
    }
    return 0;
}
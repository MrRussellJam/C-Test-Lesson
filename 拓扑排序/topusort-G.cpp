#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

char map[1001][1001];
int vis[1001];
vector<int> vec[1001];
int n;

bool dfs(int u){
    vis[u] = -1;
    for(int i = 0; i < vec[u].size() ; i++){
        int v = vec[u][i];
        if( vis[v] == -1 ) return false;
        if( !vis[v] && !dfs(v) ) return false; 
    }
    vis[u] = 1;
    return true;
}

bool topusort(){
    for(int i = 1; i <= n ;i++ ){
        if(!vis[i]){
            if(!dfs(i)) return false;
        }
    }
    return true;
}

int main(){
    int T = 0;
    cin >> T;
    while(T-- ){
        cin >> n ;
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        for(int i = 1; i <= n; i++){
            cin >> map[i];
            for(int j = 0 ; j <= n ;j++){
                if(map[i][j] == '1') vec[i].push_back(j + 1);
            }
        }
        
        bool becri = topusort();

        if(becri) cout << "YES" << endl;
        else cout << "NO" << endl;
        for(int i = 1; i <= n ; i++) vec[i].clear();
    }
    return 0;
}
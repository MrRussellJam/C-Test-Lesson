#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> vec[101];
int vis[101];
int n,m;

bool dfs(int u){
    vis[u] = -1;
    for(int i = 0; i <= vec[u].size();i++){
        int v = vec[u][i];
        if(vis[v] == -1) return fals e;
        else if(!vis[v] && !dfs(v) ) return false;
    }
    vis[u] = 1;
    return true;
}

bool topusort(){
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(!dfs(i))
                return false;
        }
    }
    return true;
}

int main(){
    while( scanf("%d%d",&n,&m) != EOF ){
        
        for(int i = 0; i < m; i++){
            int a,b;
            cin >> a >> b;
            vec[a].push_back(b);
        }

        for(int i = 0; i <= n ; i++){
            for(int j = 0; j < vec[i].size() ; j++){
                cout << vec[i][j] << endl;
            }
        }

        bool becrip = topusort();

        if(becrip) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}
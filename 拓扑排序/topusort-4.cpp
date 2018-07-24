#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;


int main(){
    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        vector<int> vec[30004];
        int vis[30004];
        int in[30004];
        int out[30004];
        int srt[30004];
        int num = 1;
        queue<int> q;
        memset(vis,0,sizeof(vis));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i = 0 ;i < m;i++){
            int a,b;
            cin >> a >> b;
            out[a]++;
            in[b]++;
            vec[a].push_back(b);
        }

        for(int i = 1;i < m;i++){
            if(in[i] == 0 ) q.push(i);
        }
        cout << " here" << endl;
        while(!q.empty()){
        cout << " here1" << endl;
            int u = q.front();
            q.pop();
            vis[u] = 1;
            srt[num++] = u;
            for(int i = 0; i < vec[u].size() ; i++){
                cout << " here2" << endl;
                int v = vec[u][i];
                in[v]--;
                if( in[i] == 0 )  q.push(i);
            }
        }

        for(int i = 1;i <= n ;i++){
            if(!vis[i]){
                srt[num] = i;
                num++;
            }
        }
        for(int i = 1; i <= n ; i++){
            cout << srt[i] << " ";
        }
    }
    return 0;
}
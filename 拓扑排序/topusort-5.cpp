#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include<algorithm>
#include<functional>

using namespace std;

int n,m;
int in[501],out[501];

int main(){

    while ( scanf("%d%d",&n,&m) != EOF ){
        vector<int> vec[501];
        priority_queue<int, vector<int>, greater<int> > q;
        memset( in , 0 , sizeof(in) );
        memset( out , 0 , sizeof(out) );
        int cnt = 0;
        int pri[501];
        for(int i = 0; i < m ; i++){
            int a,b;
            cin >> a >> b;
            out[a]++;
            in[b]++;
            vec[a].push_back(b);
        }

        for(int i = 1 ; i <= n ;i++){
            if(in[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int u = q.top();
            q.pop();
            pri[cnt++] = u;
            for(int i = 0;i < vec[u].size();i++){
                int v = vec[u][i];
                in[v]--;
                if(in[v] == 0) q.push(v);
        	}
        }
        for(int i = 0; i < n - 1 ; i++)
            cout << pri[i] << " ";
        cout << pri[n - 1] << endl;
    }

    return 0;
}
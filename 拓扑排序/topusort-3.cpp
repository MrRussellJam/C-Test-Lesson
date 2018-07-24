#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

vector<int> vec[1001];
int n;
int vis[1001];
string str[1001];
int length ;

bool dfs(int u){
    vis[u] = -1;
    for(int i = 0;i <= vec[u].size();i++){
        int v = vec[u][i];
    	cout<< u << " : << here : " << v << endl;
        if(vis[v] == -1) return false;
        else if(!vis[v] && !dfs(v) ) return false;
    }

    vis[u] = 1;

    return true;
}

bool topu(){
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= length;i++){
        if(!vis[i]){
            if(!dfs(i)){
                return false;
            }
        }
    }
    return true;
}


int main(){
    while( scanf("%d",&n) != EOF ){
    	if(n == 0) break;
        int t = n;
        int str1;
        int str2;
        length = 1;
        while(t--){
            string  a,b;
            str1 = 0;
            str2 = 0;
            cin >> a >> b;
            for(int i = 1;i<=length;i++){
                if(str[i] == a ) str1 = i;
                if(str[i] == b ) str2 = i;
            }
            if(!str1){
                str1 = length;
                str[length] = a;
                length++;
            }
            if(!str2){
                str2 = length;
                str[length] = b;
                length++;
            }
            vec[str1].push_back(str2);
        }
        length--;
        for(int i = 1;i <= length ; i++){
        	cout << str[i] << "   " << i << endl;
		}

        bool judge = topu();

        if(judge) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

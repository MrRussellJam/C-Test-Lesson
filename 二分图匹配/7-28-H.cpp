#include <iostream>
#include <string.h>

using namespace std;

bool link[1005][1005];
bool used[1005];
int girl[1005];
int n;
int all;

bool finds(int x){

    for(int i = 1;i <= n ; i++ ){
        if( !used[i] && link[x][i] ){
            used[i] = true;
            if( girl[i] == 0 || finds(girl[i]) ){
                girl[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    while(scanf("%d",&n) != EOF && n != 0){
        int m,g;
        all = 0;
        memset(link,false,sizeof(link));
        memset(girl,0,sizeof(girl));

        for(int i = 1; i <= n ;i++){
            cin >> m >> g;
            link[m][g] =true;
        }

        for(int i = 1; i <= n ;i++){
            memset(used,0,sizeof(used));
            if( finds(i) ) all++;
        }
        cout << all << endl;
    }

    
    return 0;
}
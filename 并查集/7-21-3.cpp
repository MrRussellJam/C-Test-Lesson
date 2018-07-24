#include <iostream>
#include <algorithm>

using namespace std;

int fa[1005];
int n,m;

void init(){
    for(int i = 1 ; i <= n ; i++ ) fa[i] = i;
}

int getIn(int x){
    
    if(fa[x] == x) return x;
    else return fa[x] = getIn(fa[x]);

}

void union_set(int x,int y){
    int fx = getIn(x);
    int fy = getIn(y);
    if(fx != fy) fa[fy] = fx;
    else return ;
}


int main(){
    int T ;
    cin >> T ;
    while(T--){
        cin >> n >> m;
        init();
        for(int i = 1 ; i <= m ; i++ ){
            int a,b;
            cin >> a >> b;
            union_set( a , b );
        }

        sort(fa + 1,fa + n + 1);
        int sum = 1 ; 
        for( int i = 1 ; i <= n - 1 ; i++ ) 
            if(fa[i] !=fa[i + 1] ) sum++;
        cout << sum << endl;
    }

    return 0;
}
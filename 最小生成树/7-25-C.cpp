#include <iostream>
#include <algorithm>

using namespace std;

struct Dep{
    int x;
    int y;
    int line;
};

bool cmp(Dep p1,Dep p2){
    if( p1.line < p2.line ) return true;
    return false;
}

int fa[105];

int getIn(int x){
    if(fa[x] == x) return x;
    else return fa[x] = getIn(fa[x]);
}


int main(){
    int n;
    while(scanf("%d",&n) && n != 0 ){
        int sum = 0;
        int num = 0;
        struct Dep deps[5000];
        for(int i = 1 ; i <= n ; i++ ) fa[i] = i;
        for(int i = 1; i <= n*(n-1)/2 ; i++ ){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            deps[i].x = a;
            deps[i].y = b;
            deps[i].line = c;
        }
        sort(deps + 1 , deps + n*(n - 1)/2 + 1 , cmp);
        for(int i = 1; i <= n*(n - 1)/2 ; i++){
            int fx = getIn(deps[i].x);
            int fy = getIn(deps[i].y);
            if(fx != fy){
                fa[fy] = fx;
                sum += deps[i].line;
                num++;
            }
            if( num == n) break;
        }
        cout << sum << endl;
    }
    return 0;
}
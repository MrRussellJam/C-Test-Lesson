#include <iostream>
#include <algorithm>

using namespace std;

struct Dep{
    int x;
    int y;
    int line;
};

bool cmp(Dep p1 , Dep p2){
    if( p1.line < p2.line )return true;
    return false;
}

int fa[100];
int getIn(int x){
    if(fa[x] == x) return x;
    else return fa[x] = getIn(fa[x]);
}

int main(){
    int n;
    while( scanf("%d" , &n) != EOF ){
        int s = 1;
        struct Dep deps[5000];
        for(int i = 0;i <= n ; i++) fa[i] = i;
        for(int i = 1; i <= n; i++ ){
            for(int j = 1; j <= n ; j++ ){
                int a;
                scanf("%d",&a);
                if(i==j) continue;
                deps[s].x = i;
                deps[s].y = j;
                deps[s].line = a;
            }
        }
        sort( deps + 1 , deps + s + 1 , cmp);
        int m;
        scanf("%d",&m);
        for(int i = 1; i <= m ;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            int x,y;
            x = getIn(a);
            y = getIn(b);
            if( x != y ){
                fa[y] = x;
            }
        }
        int sum = 0;
        for(int i = 1; i <= s ;i++){
            int x = getIn(deps[i].x);
            int y = getIn(deps[i].y);
            if( x != y ){
                fa[y] = x;
                sum += deps[i].line;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
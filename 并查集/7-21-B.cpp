#include <iostream>
#include <string.h>
using namespace std;

int fa[100005];
int sum;

void init(){
    for(int i = 0 ; i < 100005 ; i++) fa[i] = i;
    sum = 0;
}

int getIn(int x){
    sum++;
    if(fa[x] == x) return x;
    else return fa[x] = getIn(fa[x]);
}

void union_set(int x,int y){
    int fx = getIn(x);
    int fy = getIn(y);
    if(fx != fy){
        fa[fy] = fx;

    }else {
        return ;
    }
}

int max(int a,int b){
    return a>b?a:b;
}

int main(){
    int n;
    
    while(scanf("%d",&n) != EOF){
        int a,b;
        init();
        int t = 0;
        for(int i = 0;i < n ; i++) {
            cin >> a >> b;
            t = max( t , max( a , b ) );
            union_set(a,b);
        }
        int tong[100005];
        memset(tong,0,sizeof(tong));
        for(int i = 1; i <= t ; i++ ) getIn(i);
        int temp = 0;
        for(int i = 0; i <= t ; i++ ) {
            tong[fa[i]]++;
            if( tong[fa[i]] > temp ) temp = tong[fa[i]];
        }
        cout << temp << endl;
    }
    return 0;
}
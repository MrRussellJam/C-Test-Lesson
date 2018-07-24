#include <iostream>

using namespace std;

int fa[10005];
bool check;
int a,b;

void init(){
    for(int i = 0;i < 10005 ; i++) fa[i] = i;
}

int getIn(int x){
    if(fa[x] == x) return x;
    else return fa[x] = getIn(fa[x]);
}

void union_set(int x,int y){
    int fx,fy;
    fx = getIn(x);
    fy = getIn(y);
    if(check && fx != fy ) fa[fy] = fx;
    else check = false;
}

int main(){
    while(1){
        init();
        check = true;
        bool out = false;
        while(1){
        	scanf("%d%d",&a,&b);
            if(a == -1 && b == -1) {
                out = true;
                break;
            }
            if(a == 0 && b == 0) break;
            union_set(a,b);
        }
        if(out) break;
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
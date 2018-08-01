#include <iostream>
#include <algorithm>

using namespace std;

struct dep{
    int x;
    int y;
    int line;
    int be;
    // const bool operator< (const dep& rhs) const{
    //     return line < rhs.line;
    // }
    // const bool operator> (const dep& rhs) const{
    //     return be > rhs.be;
    // }
};

bool cmp(dep p1 , dep p2){
    if(p1.be > p2.be ) return true;
    else{
        if(p1.be == p2.be) {
            if(p1.line < p2.line) {
                return true;
            }
        }
    }
    return false;
}

int fa[101];

int getIn(int x){
    if(fa[x] == x) return x;
    else return fa[x] = getIn(fa[x]);
}

int main(){
    int n;
    while(1){
        cin >> n;
        int sum = 0;
        int num = 0;
        if( !n ) break;
        struct dep des[4955];
        for(int i = 1 ;i < 101 ; i++) fa[i] = i;
        for(int i = 1; i <= n*((n-1)/2) ; i++){
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            des[i].x = a;
            des[i].y = b;
            des[i].line = c;
            des[i].be = d;
        }
        sort(des + 1 , des + 1 + n*((n-1)/2) , cmp);
        for(int i = 1; i <= n*((n-1)/2) ; i++){
        	bool run = true;
            int fx = getIn(des[i].x);
            int fy = getIn(des[i].y);
            if(des[i].be){
                fa[fy] = fx;
                num++;
                run = false;
            }
            if(fx!=fy && run){
                fa[fy] = fx;
                sum += des[i].line;
                num++;
            }
            if(num == n -1 ) break;
        }
        cout << sum << endl;

    }
    return 0;
}

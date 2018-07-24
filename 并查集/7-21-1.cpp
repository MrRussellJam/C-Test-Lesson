#include <iostream>
#include <algorithm>

using namespace std;

int Fa[1005];
int sum;


int getIn(int x){
    if( Fa[x] == x ) return x;
    else{
    	Fa[x] = getIn(Fa[x]);
    	return Fa[x];
	}
}

void unionC(int x,int y){
    int fx = getIn(x);
    int fy = getIn(y);
    if( fx != fy ) {
        Fa[fy] = fx;
    }
}

int main(){
    int m,n;
    while(1){
        cin >> n ;
        if( n == 0 ) break;
        cin >> m ;
        int a,b;
        sum = 0;
        for(int i = 1 ; i <= n ; i++ ) Fa[i] = i;
        for(int i = 1 ; i <= m ; i++ ){
            cin >> a >> b ;
            unionC( a , b );
        }
		for(int i = 1;i <= n ;i++) getIn(i);
        sort(Fa + 1 , Fa + n + 1 );
        for(int i = 1;i <= n - 1 ; i++){
        	if(Fa[i] != Fa[i + 1] ) sum++;
        	else continue;
		}
		cout << sum << endl;
    }
    return 0;
}
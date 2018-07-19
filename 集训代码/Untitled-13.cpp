#include <iostream>

using namespace std;

int sum;
int n;

int dfs(int tab){
	if(tab == 0) return 0; 
	if(tab == 1) return 1;
	if(tab == 2) return 2;
	return dfs( tab - 1) + dfs( tab - 2 ) ; 
}

int main(){
    int T;
    cin >> T;
    while( T-- ){
    	sum = 0;
        cin >> n;
        sum = dfs( n - 1 );
        cout << sum << endl;
    }
}
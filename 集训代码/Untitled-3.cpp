#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

struct dep{
	int x;
	int y;
}deps[1000];

bool Compare(const dep &a,const dep &b){
	return a.x > b.x;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		int line;
		cin >> n;
		bool flag = true;
		memset( deps , 0 , sizeof(deps) );
		for(int i = 0; i < n; i++){
			cin >> deps[i].x >> deps[i].y;
		}
		sort(deps,deps + n,Compare);
		if(flag) cout << "YES" <<endl;
		else cout << "NO" <<endl;
	}
	return 0;
}
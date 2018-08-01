#include <iostream>
#include <algorithm>

using namespace std;

struct dep{
	int x;
	int y;
	int line;
	int be;
	const bool operator< (const dep& rhs) const { //重载比较运算符
		return line < rhs.line;		      //根据边值从小到大排序
	}
};
int fa[1000];

int getIn(int x){
	if(fa[x] == x )return x;
	else return fa[x] = getIn(fa[x]); 
}


int main(){
	int n,m;
	while(1){
		scanf("%d%d",&n,&m);
		if(n == 0) break;
		int sum = 0;
		int num = 0;
		for(int i = 1 ; i <= m ; i++ ) fa[i] = i;
		struct dep des[1000];
		for(int i = 1; i <= n ; i ++) {
			int a,b,c;
			cin >> a >> b >> c;
			des[i].x = a;
			des[i].y = b;
			des[i].line = c;
		}
		sort(des + 1 , des+n+1);
		for(int i = 1;i <= n; i++){
			int fx = getIn(des[i].x);
			int fy = getIn(des[i].y);
			if(fx != fy){
				fa[fy] = fx;
				sum += des[i].line;
				num++;
			}
			if(num == m - 1) break;
		}
		if(num == m - 1 )cout << sum << endl;
		else cout << "?" << endl;
	}
	return 0;
}
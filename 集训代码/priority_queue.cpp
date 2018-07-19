#include <iostream>
#include <queue>

using namespace std;

int main(){
	while(1){
		int n,m;
		cin >> n >> m;
		int t;
		int sum = 0;
		if(n == 0 && m == 0) break;
		priority_queue<int, vector<int>, greater<int> > dragon;
		priority_queue<int, vector<int>, greater<int> > kin;
		for(int i = 0;i < n; i++ ){
			cin >> t;
			dragon.push(t);
		}
		for(int i = 0;i < m; i++ ){
			cin >> t;
			kin.push(t);
		}
		
		if( n > m ) {
			cout << "Loowater is doomed!" <<endl;
			continue;
		}
		
		while( !kin.empty() && !dragon.empty() ){
			if(kin.top() >= dragon.top()) {
				sum = sum + kin.top();
				dragon.pop();
			}
			kin.pop();
		}
		
		if(dragon.empty())  cout << sum <<endl;
		else cout << "Loowater is doomed!" <<endl;
		
	}
	
	return 0;
}
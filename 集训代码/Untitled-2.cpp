#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
	while(1){
		string a;
		char str;
		set<string> s;
		while(1){
			cin>>a;
			if(a=="#")return 0;
			s.insert(a);
			str=cin.get();
			if(str=='\n') break;
		}
		cout<<s.size()<<endl;
	}
	return 0;
}

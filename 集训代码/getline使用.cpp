#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;

int main(){
	string s1;
	while(1){
		int sum=0;
		getline(cin,s1);
		if(s1[0]=='#') break;
		string s2;
		stringstream ss(s1);
		set<string> s;
	
		while(ss>>s2){
			s.insert(s2);
		}
		cout<<s.size()<<endl;
	}
	return 0;
}

// #include<sstream>
// #include<iostream>
// using namespace std;
// int main()
// {
//         string line,word;
//         while(getline(cin,line))
//         {
//                 stringstream stream(line);
//                 cout<<stream.str()<<endl;
//                 while(stream>>word){cout<<word<<endl;}
//         }
//         return 0;
// }
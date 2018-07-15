#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    while(1){
        set<string> s;
        char ch;
        while(1){
        	char ch2[100];
        	cin>>ch2;
            if(getchar()=='\n') break;
            if(getchar()=='#') break;
        	string ch1;
        	cout<<ch2<<endl;
            s.insert(ch2);
//
//		    set<string>::iterator ite1 = ch1.begin();
//		    set<string>::iterator ite2 = ch1.end();
//		    for(;ite1!=ite2;ite1++)
//		    {
//		        cout<<*ite1;
//		    }
//		    cout<<endl;
        }
        cout<<s.size()<<endl;
    }
    return 0;
}

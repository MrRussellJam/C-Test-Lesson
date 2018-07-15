#include <iostream>

using namespace std;
int fath[100];


int main(){
    int t;
    while(scanf("%d",&t)!=EOF){
        int s;
        for(s=0;s<t;s++) cin>>fath[s];
        int i=2;
        bool see=false;
        while(1){
            for(s=0;s<t;s++){
                if(i%fath[s]!=0){
                    see=false;
                    break;
                }
                else see=true;
            }
            if(see){
                break;
            }else{
                i++;
                continue;
            }
        }
        cout<<i<<endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int sum=0;
        int step;
        cin>>step;
        int a=step-1;
        while(1){
            a=step-2;
            if(a>=0)sum++;
            else {
                sum++;
                break;
            }
        }
        printf("%d",sum);

    }
    return 0;
}

#include <iostream>

using namespace std;

int check(int a){
    int sum=0;
    int i=2;
    int j;
    bool ischeck = true;
    while(i<=a){
        for(j=2;j<=i;j++) {
            if(i == j && ischeck || i % j != 0) {
                cout<<"here be run by true"<<endl;
                ischeck = true;
            }else {
                ischeck = false;
                break;
                cout<<"here be run by false"<<endl;
            }
        }
        if(ischeck) {
            if(a%i==0){
                cout<<"here be run"<<endl;
                cout<<i<<endl;
                sum++;
                a=a/i;
            }
        }
        ischeck = false;
        i++;
    }
    return sum;
}

int main(){
    int a;
    while(1){
        cin>>a;
        if(a==0) break;
        // if(a%2!=0) continue;
        int sum;
        sum=check(a);
        cout<<sum<<endl;

    }
    return 0;
}
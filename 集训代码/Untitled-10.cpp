#include <iostream>
#include <string>

using namespace std;

int money[6]={100,50,10,5,2,1}

int people[101];

bool canRun = true;



int main(){

    while(1){
        int T;
        memset(people,0,sizeof(people));
        cin>>T;
        if(T==0) break;
        for(int i=0;i<T;i++){
            cin>>people[i];
        }
        int sum=0;
        for(int i=0;i<T;i++){
            int head=0;
            int tail=6;
            while(head!=tail){
                if(people[i]-money[head]>=0){
                    sum++;
                    people[i]-=money[head];
                    continue;
                }
                head++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
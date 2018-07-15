#include <iostream>
#include <string.h>

using namespace std;
int queue[100];

int sumA(int i){
    int j=0;
    int sum=0;
    for(j=0;j<i;j++) sum+=queue[j];
    sum=sum/i;
    return sum;
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(queue,0,sizeof(queue));
        queue[0]=2;
        for(int i=1;i<n;i++){
            queue[i]=queue[i-1]+2;
        }
        cout<<"here 1"<<endl;
        int head=0;
        int tail=n;
        int judge=1;
        int sum=0;
        bool see=false;
        while(head!=tail){
            if(judge!=m && head==tail-1){
                cout<<"can 1"<<endl;
                sum = sumA(n);
                cout<<sum<<endl;
            }else if(judge!=m){
                cout<<"can 2"<<endl;
                sum+=queue[head];
                judge++;
            }else if(judge==m){
                cout<<"can 3"<<endl;
                sum+=queue[head];
                sum=sum/m;
                cout<<sum<<" ";
                sum=0;
                judge=1;
            }
            cout<<sum<<" "<<endl;
            head++;
        }
    }
    return 0;
}

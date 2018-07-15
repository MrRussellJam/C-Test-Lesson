#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

struct Queue{
    int i;
    int j;
    int mid;
}queue[100];

bool Compare(const Queue &a,const Queue &b){
    return a.i<b.i;
}

int main(){
    int s;
    cin>>s;
    int j,k;
    for(int i=0;i<s;i++){
        cin>>j>>k;
        queue[i].i=j;
        queue[i].j=k;
        queue[i].mid=k-j;
    }
    sort(queue,queue+s,Compare);
    int sum=1;
    for(int i=1;i<s;i++){
    }

   return 0;
}
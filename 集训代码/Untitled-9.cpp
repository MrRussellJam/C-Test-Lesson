#include <iostream>
#include <algorithm>

using namespace std;

struct protime{
    int first;
    int end;
}allpro[101];

bool Compare(const protime &a,const protime &b){
    return a.end<b.end;
}

int main(){
    int T;
    cin>>T;
    int i=0;
    while(T--){
        cin>>allpro[i].first>>allpro[i].end;
        i++;
    }
    sort(allpro,allpro+i,Compare);
    
    int j=1;
    int sum=1;

    while(j!=i){
        if(queue[j].first>=queue[j-1].end) sum++;
        j++;
    }
    cout << sum;

    return 0;
}

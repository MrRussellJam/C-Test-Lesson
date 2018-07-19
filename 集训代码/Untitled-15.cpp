#include <iostream>
#include <stack>
#include <string.h>

using namespace std;


int main(){
    while(1){
        int n;
        cin >> n;
        if( n == 0 ) break;
        while(1){
            stack<int> sta;
            bool out = false;
            int outtrain[1000];
            for(int i = 0;i < n;i++){
                cin >> outtrain[i];
                if(outtrain[0] == 0){
                    out = true;
                }
            }
            if(out) break;
            int i = 1;
            sta.push(i);
            int head = 0;
            int tail = n;
            while(!sta.empty()){
                if(sta.top == outtrain[head]){
                    sta.pop();
                    head++;
                }
                if(i != n){
                    i++;
                    sta.push[i];
                }
                if( i == n && sta.top != outtrain[head] ){
                    out = false;
                    break;
                }
            }
            if( !out ) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}
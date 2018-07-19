#include <iostream>
#include <set>

using namespace std;


int main(){
    int n,m;
    while(1){
        set<int> sets;
        int line = 0;
        int t;
        int flag = 0;
        while(1){
            cin >> n >> m;
            if(n == 0 && m == 0) break;
            if(n == -1 && m == -1) break;
            line++;
            t = sets.size();
            sets.insert(n);
            sets.insert(m);
            if(t == sets.size() ) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            cout << "NO" <<endl;
            continue;
        }
        if(line == sets.size() - 1) cout << "YES" << endl;
        else cout << "NO" <<endl;
        if(n == -1 && m == -1) break;
    }

    return 0;
}
#include <iostream>

using namespace std;

int way[1000];
int number[1000];
bool choose[2] = { true , false };
int sum;
int tempsum;
int n;
int m;
int foot;
int temp;
int wayk;

void printSum(int i){
    for(int j = 0;j < i-1;j++){
        cout << number[j] << "+" ;
    }
    cout << number[i - 1] <<endl;
}

void dfs( bool tis ){
    if( foot == m ) return ;
    if( tis ){
        cout << "bool : " << tis << endl;
        tempsum = tempsum + number[foot];
        way[wayk] = number[foot];
        wayk++;
    }
    if( tempsum > n ) return;

    if( tempsum == n ){
        cout << "tempsum : " << tempsum << endl;
        printSum(wayk);
    }
    foot++;

    for(int i = 0;i < 2;i++){
        dfs( choose[i] );
    }

    foot--;
    if(tis) {
        tempsum = tempsum - number[foot];
        wayk--;
        way[wayk] = 0;
    }

}


int main(){
    while(1){
        cin >> n >> m;
        temp = 0;
        wayk = 0;
        foot = 0;
        if( n == 0 && m == 0 ) break;

        for(int i = 0; i < m ;i++) cin >> number[i];

        for(int i = 0;i < 2;i++)
            dfs( choose[i] );

    }
    return 0;
}
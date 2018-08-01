#include <iostream>
#include <string.h>

#define MAXN 200004

using namespace std;

int sum[MAXN<<2];
int n,m;
int bigger;

void Push(int ai){
    sum[ai] = sum[ai << 1] + sum[ai << 1 | 1];
}

void Build(int l , int r , int ai){
    if(l == r){
        scanf("%d",&sum[ai]);
        return ;
    }

    int mid = (1 + r) >> 1;
    Build(l , mid , ai<<1);
    Build(mid + 1 , r , ai<<1|1);
    Push(ai);
}

void Change(int L , int C , int l , int r , int ai){
    if( l == r ){
        sum[ai] = C;
        return ;
    }

    int mid = ( l + r ) >> 1;

    if( L <= m ) Change( L , C , l , mid , ai<<1);
    else         Change( L , C ,mid + 1 , r , ai<<1|1);

    Push(ai);
}

void findmax( int L , int R , int l , int r , int ai){
    if( l == r ){
        if(sum[ai] > bigger) bigger = sum[ai];
        return ;
    }

    int mid = ( l + r ) >> 1;

    if( L <= mid ) findmax( L , R , l , mid , ai<<1);
    if( R >  mid ) findmax( L , R , mid + 1 , r , ai<<1|1);
}

int main(){
    cin >> n >> m;
    char chose;
    Build(1,n,1);
    for(int i = 1; i <= m ;i++){
        bigger = 0;
        int a,b;
        scanf("%d",&chose);
        scanf("%d%d",&a,&b);
        switch(chose){
            case 'Q':{
                findmax(a , b , 1 , n , 1);
                cout << bigger << endl;
                break;
            }
            case 'U':{
                Change(a , b ,  1 , n , 1);
                break;
            }
        }
    }
    return 0;
}
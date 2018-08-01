#include <iostream>
#include <string.h>

#define MAXN 100000

using namespace std;

int sum[MAXN << 2];
int lazy[MAXN << 2];

void PushDown(int ai,int ln,int rn){
    if(lazy[ai]){
        lazy[ai << 1] += lazy[ai];
        lazy[ai << 1 | 1] += lazy[ai];

        sum[ai << 1] += lazy[ai]*ln;
        sum[ai<<1|1] += lazy[ai]*rn;
        
        lazy[ai] = 0;
    }
}

void Push(int ai){
    sum[ai] = sum[ai<<1] + sum[ai<<1|1];
}

void Build(int l,int r,int ai){
    if( l == r ){
        scanf("%d",&sum[ai]);
        return ;
    }
    int m = ( l + r ) >> 1 ;
    Build(l , m , ai << 1) ;
    Build(m + 1 , r , ai << 1 | 1 ) ;
    Push(ai) ;
}

void Updata(int L , int R , int C , int l , int r , int ai){
    if( L <= l && r <= R ){
        sum[ai] += C*(r -  l + 1);
        lazy[ai] += C;
        return ;
    }

    int m = ( l + r ) >> 1;

    PushDown(ai , m - l + 1 , r - m);

    if( L <= m ) Updata( L , R , C , l , m , ai << 1);
    if( R > m )  Updata( L , R , C , m + 1 , r , ai << 1 | 1 );

    Push(ai);
}


int Query( int L , int R , int l , int r , int ai){
    if(L <= l && R >= r){ 
        return sum[ai];
    }
    int m = (l + r) >> 1 ;
    PushDown( ai , m - l + 1 , r - m );
    int ans = 0;
    if( L <= m )ans += Query( L , R , l , m , ai << 1);
    if( R > m )ans += Query( L , R , m + 1 , r , ai << 1 | 1);
    return ans;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    Build(1,n,1);
    for(int i = 1; i <= m ; i++){
        getchar();
        char choose;
        scanf("%c",&choose);
        
        switch (choose)
        {
            case 'C':{
                int a,b,c;
                scanf("%d%d%d",&a,&b,&c);
                Updata( a , b , c , 1 , n , 1 );
                break;
			} 
            case 'Q':{
                int a,b;
                scanf("%d%d",&a,&b);
                printf("%d\n" , Query( a , b , 1 , n , 1) );
                break;
			} 
            default:
                break;
        }
    }
    return 0;
}
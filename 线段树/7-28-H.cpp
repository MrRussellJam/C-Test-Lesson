#include <iostream>
#include <string.h>

#define MAXN 100000

using namespace std;

int sum[MAXN<<2];
int Add[MAXN<<2];

void Push(int ai){
    sum[ai] = sum[ai<<1] + sum[ai<<1|1];
}

void PushDown(int ai,int ln,int rn){
	//如果存在标记 
	if(Add[ai]){
		//下推标记 
		Add[ai<<1]+=Add[ai];
		Add[ai<<1|1]+=Add[ai];
		//修改子节点的g_Sum使与标记对应 
		sum[ai<<1]+=Add[ai]*ln;
		sum[ai<<1|1]+=Add[ai]*rn;
		//清除本节点标记 
		Add[ai]=0;
	}
} 

void Build(int L,int R,int l,int r,int ai){

    if( l == r && L <= l && R >= r ){
        cout << " here " << endl;

        sum[ai] += 1;
        return ;
    }
    if( l == r ) return ;

    int m = ( l + r ) >> 1;

    PushDown(ai , m - l + 1 , r - m);
    
    Build(L , R , l , m , ai << 1);
    Build(L , R , m + 1 , r , ai << 1 | 1);

}

void Find(int l , int r , int ai){
    if( l == r ){
        printf("%d ",sum[ai]);
        return ;
    }

    int m = ( l + r ) >> 1;

    Find( l , m , ai << 1 );
    Find(m + 1 , r , ai << 1 | 1 );

}

int main(){
    int n;
    while(scanf("%d",&n) && n != 0){

        memset(sum,0,sizeof(sum));

        for(int i = 1 ; i <= n ;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            Build(a , b , 1 , n , 1);
        }
        Find(1,n,1);
    }
    return 0;
}
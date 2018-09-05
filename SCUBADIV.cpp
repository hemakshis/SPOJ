#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;
const int C=1e3+5,O=25,N=85;
const long INF=1e9+7;
struct cylinder
{
    int o;
    int n;
    int w;
} cy[C];
long dp[C][O][N];
int t,o,n,c,p,q,r;
void init(){
    for(int i=0;i<C;i++){
        for(int j=0;j<O;j++){
            for(int k=0;k<N;k++){
                dp[i][j][k]=-1;
            }
        }
        cy[i].n=0;
        cy[i].o=0;
        cy[i].w=0;
    }
}

int cal(int x,int y,int z){
    if(y==0 && z==0)
        dp[x][y][z]=0;
    else if(x==0)
        dp[x][y][z]=INF;
    else if(dp[x][y][z]!=-1)
        return dp[x][y][z];
    else dp[x][y][z]=min(cal(x-1,y,z),cal(x-1,max(y-cy[x-1].o,0),max(z-cy[x-1].n,0))+cy[x-1].w);
    return dp[x][y][z];
}

int main(void)
{
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d",&o,&n);
        scanf("%d",&c);
        for(int i=0;i<c;i++){
            scanf("%d%d%d",&p,&q,&r);
            cy[i].o=p;
            cy[i].n=q;
            cy[i].w=r;
        }
        printf("%ld\n",cal(c,o,n));
    }
    return 0;
}

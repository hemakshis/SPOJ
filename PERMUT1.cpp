#include <iostream>
#include <stdio.h>

using namespace std;
const int N=51, K=1500;
long long dp[N][K];
void initialize(){
    for(int i=0;i<N;i++)
        for(int j=0;j<K;j++)
            dp[i][j]=0;
}
void cal(){
    long long sum,j,k,i;
    dp[1][0]=1;
    for(int i=0;i<=12;i++){
        sum=i*(i-1)/2;
        for(int j=0;j<=sum;j++){
            for(int k=0;k<i&&j-k>=0;k++)
                dp[i][j]+=dp[i-1][j-k];
        }
    }
}
int main(void)
{
    int t;
    scanf("%d",&t);
    initialize();
    int n[t+5],k[t+5];
    for(int i=0;i<t;i++){
        scanf("%d%d",&n[i],&k[i]);
    }
    cal();
    for(int i=0;i<t;i++){
        printf("%lld\n",dp[n[i]][k[i]]);
    }
}

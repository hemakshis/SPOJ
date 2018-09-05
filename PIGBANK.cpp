#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <vector>
using namespace std;
const int N=1e5+5;
const long INF=100000000000000007;
long long dp[N];
long long x,y,v[N],w[N],n;

long long solve(long long W){
    dp[0]=0;
    for(int i=1;i<=W;i++){
        for(int j=0;j<n;j++){
            if(i>=w[j]){
                dp[i]=min(dp[i],dp[i-w[j]]+v[j]);
            }
        }
    }
    if(dp[W]!=INF)
        return dp[W];
    else return -1;
}
int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        long long e,f;
        for(int i=0;i<N;i++){
            dp[i]=INF;
            v[i]=0;
            w[i]=0;
        }
        scanf("%lld%lld",&e,&f);
        long long W=f-e;
        scanf("%lld",&n);
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&x,&y);
            v[i]=x;
            w[i]=y;
        }
        if(W==0){
            printf("The minimum amount of money in the piggy-bank is 0.\n");
            continue;
        }
        long long ans=solve(W);
        if(ans>=0 && ans!=INF){
            printf("The minimum amount of money in the piggy-bank is %ld.\n",ans);
        }
        else printf("This is impossible.\n");
    }
    return 0;
}

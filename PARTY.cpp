#include <iostream>
#include <stdio.h>
using namespace std;
int dp[2005][2005];
int cost;
void knapsack(int v[],int w[],int W,int n){
    cost=0;
    for(int i=0;i<=W;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(w[i]<=j){
                dp[i][j]=max(dp[i-1][j],v[i]+dp[i-1][j-w[i]]);
            }
            else dp[i][j]=dp[i-1][j];
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    int i=n, j=W;
    while(j>=0 && dp[n][W]==dp[n][j]){
        j--;
    }
    printf("%d %d\n",j+1,dp[n][W]);
}
int main(void)
{
    while(1){
        int W,n;
        scanf("%d%d",&W,&n);
        if(W==0 && n==0)
            break;
        int v[n+5],w[n+5];
        v[0]=0; w[0]=0;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&w[i],&v[i]);
        knapsack(v,w,W,n);
    }
    return 0;
}

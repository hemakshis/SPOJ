#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct query
{
    int p;
    int n;
    int id;
};

long long dp[70][15];
void solve(int n){
    for(int i=0;i<10;i++){
        dp[2][i]=10-i;
        dp[2][10]+=dp[2][i];
    }
    //cout<<"value for n = 2 is "<<dp[2][10]<<endl;
    for(int i=3;i<=n;i++){
        //cout<<"i = "<<i<<endl;
        for(int j=0;j<10;j++){
            if(j==0)
                dp[i][j]=dp[i-1][10];
            else
                dp[i][j]=dp[i][j-1]-dp[i-1][j-1];
            //cout<<dp[i][j]<<endl;
            dp[i][10]+=dp[i][j];
        }
        //cout<<"value for n = "<<i<<" is "<<dp[i][10]<<endl;
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    query q[t+5];
    int x,y,n=-1;
    for(int i=0;i<70;i++)
        for(int j=0;j<15;j++)
            dp[i][j]=0;
    for(int i=0;i<t;i++){
        scanf("%d%d",&x,&y);
        q[i].id=i+1;
        q[i].p=x;
        q[i].n=y;
        n=max(n,q[i].n);
    }
    solve(n);
    for(int i=0;i<t;i++){
        if(q[i].n==1){
            printf("%d 10\n",q[i].id);
            continue;
        }
        printf("%d %lld\n",q[i].id,dp[q[i].n][10]);
    }
    return 0;
}

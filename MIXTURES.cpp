#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
long long dp[105][105];
int n,SUM[105][105],a[105];
void initialize(){
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            dp[i][j]=LONG_MAX;
            SUM[i][j]=-1;
        }
    }
}
int sum(int i,int j){
    if(SUM[i][j]==-1){
        int val=0;
        for(int k=i;k<=j;k++){
            val+=a[k];
            val=val%100;
        }
        SUM[i][j]=val;
    }
    //cout<<"SUM = "<<SUM[i][j]<<endl;
    return SUM[i][j];
}
long long mixtures(int i,int j){
    if(i==j)
        return 0;
    if(dp[i][j]!=INT_MAX)
        return dp[i][j];
    else{
        for(int k=i;k<j;k++){
            dp[i][j]=min(dp[i][j],mixtures(i,k)+mixtures(k+1,j)+sum(i,k)*sum(k+1,j));
        }
        //cout<<"dp[i][j] = "<<dp[i][j]<<endl;
        return dp[i][j];
    }
    //cout<<"dp[i][j] = "<<dp[i][j]<<endl;
}

int main(void)
{
    while(scanf("%d",&n)>0){
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        initialize();
        if(n==1){
            printf("0\n");
            continue;
        }
        mixtures(0,n-1);
        printf("%lld\n",dp[0][n-1]);
    }
    return 0;
}

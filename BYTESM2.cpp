#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#define NIL -1
using namespace std;
long dp[105][105];
int grid[105][105],n,m;
void initialize(){
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            dp[i][j]=-1;
            grid[i][j]=-1;
        }
    }
}
long cal(int i,int j){
    if(i>=n || j>=m || i<0 || j<0)
        return INT_MAX;
    if(dp[i][j]==-1){
        if(i==0){
            dp[i][j]=grid[i][j];
            //cout<<"i = "<<i<<" j = "<<j<<" dp = "<<dp[i][j]<<endl;
        }
        else{
            if(i<n && i>=0 && j<m && j>=0){
                dp[i][j]=grid[i][j]+min(cal(i-1,j),min(cal(i-1,j-1),cal(i-1,j+1)));
                //cout<<"i = "<<i<<" j = "<<j<<" dp = "<<dp[i][j]<<endl;
            }
        }
    }
    return dp[i][j];
}
int main(void)
{
    initialize();
    long maxval=INT_MAX;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&grid[i][j]);
    for(int j=0;j<m;j++)
        maxval=min(maxval,cal(n-1,j));
    printf("%ld\n",maxval);
    return 0;
}

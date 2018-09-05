#include <iostream>
#include <stdio.h>
#include <vector>
#define NIL -1
using namespace std;
long dp[2005][2005],n;
int prices[2005];
long sell(int st,int en){
    if(st>en)
        return 0;
    if(dp[st][en]!=-1){
        //cout<<"dp["<<st<<"]["<<en<<"] = "<<dp[st][en]<<endl;
        return dp[st][en];
    }
    int year=n-(en-st+1)+1;
    dp[st][en]=max(sell(st+1,en)+year*prices[st],sell(st,en-1)+year*prices[en]);
    return dp[st][en];
}

int main(void)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&prices[i]);
    }
    /*
    for(int i=0;i<n;i++){
        cout<<prices[i]<<" ";
    }
    cout<<"\n";
    */
    for(int i=0;i<2005;i++)
        for(int j=0;j<2005;j++)
            dp[i][j]=-1;
    printf("%ld\n",sell(0,n-1));
    return 0;
}

#include <iostream>
#include <stdio.h>

using namespace std;
const int N=1005;
int dp[N][N],p1,p2,n,a[N],sum,t,ans;

void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j]=-1;
        }
    }
}

int cal(int st,int en){
    if(st>en)
        return 0;
    else if(dp[st][en]!=-1)
        return dp[st][en];
    else if((en-st)%2==1){
        dp[st][en]=max(a[st]+cal(st+1,en),a[en]+cal(st,en-1));
        return dp[st][en];
    }
    else{
        if(a[st]>=a[en]){
            dp[st][en]=cal(st+1,en);
            return dp[st][en];
        }
        else{
            dp[st][en]=cal(st,en-1);
            return dp[st][en];
        }
    }
    return dp[st][en];
}

int main(void)
{
    t=0;
    while(1){
        init();
        scanf("%d",&n);
        if(n==0)
            break;
        t++;
        sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        p2=0;
        ans=cal(0,n-1);
        p2=sum-ans;
        cout<<"In game "<<t<<", the greedy strategy might lose by as many as "<<ans-p2<<" points."<<endl;
    }
    return 0;
}

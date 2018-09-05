#include <iostream>
#include <stdio.h>

using namespace std;
const int H=1005,A=1005;
long dp[3][H][A];
/*  0-->air
    1-->water
    2-->fire
*/
void initialize(){
    for(int i=0;i<3;i++)
        for(int j=0;j<H;j++)
            for(int k=0;k<A;k++)
                dp[i][j][k]=-1;
}
long cal(int i,int h,int a){
    if(h<=0 || a<=0)
        return 0;
    else if(dp[i][h][a]!=-1)
        return dp[i][h][a];
    else{
        if(i==0)
            dp[i][h][a]=1+max(cal(1,h-5,a-10),cal(2,h-20,a+5));
        else if(i==1)
            dp[i][h][a]=1+max(cal(0,h+3,a+2),cal(2,h-20,a+5));
        else
            dp[i][h][a]=1+max(cal(0,h+3,a+2),cal(1,h-5,a-10));
        return dp[i][h][a];
    }
}
int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        initialize();
        int h,a;
        long ans=-1;
        scanf("%d%d",&h,&a);
        for(int i=0;i<3;i++)
            ans=max(ans,cal(i,h,a));
        printf("%ld\n",ans-1);
    }
    return 0;
}

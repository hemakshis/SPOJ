#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
using namespace std;
int k,l,m;
char call(int n){
    char dp[n+1];
    dp[0]='B'; dp[1]='A';
    for(int i=2;i<=n;i++){
        if(i<k && i<l){
            if(dp[i-1]=='B')
                dp[i]='A';
            else dp[i]='B';
        }
        else if(i<k){
            if(dp[i-1]=='B' || dp[i-l]=='B')
                dp[i]='A';
            else dp[i]='B';
        }
        else if(i<l){
            if(dp[i-1]=='B' || dp[i-k]=='B')
                dp[i]='A';
            else dp[i]='B';
        }
        else{
            if(dp[i-1]=='B' || dp[i-k]=='B' || dp[i-l]=='B')
                dp[i]='A';
            else dp[i]='B';
        }
    }
    return dp[n];
}
int main(void)
{

    scanf("%d%d%d",&k,&l,&m);
    int n[m+1];
    for(int i=0;i<m;i++){
        scanf("%d",&n[i]);
    }
    for(int i=0;i<m;i++){
        printf("%c",call(n[i]));
    }
    return 0;
}

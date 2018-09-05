#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

long countOperations(string& s1,string& s2,int l1,int l2){
    long dp[l1+1][l2+2];
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
    }
    return dp[l1][l2];
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        printf("%ld\n",countOperations(s1,s2,s1.length(),s2.length()));
    }
    return 0;
}

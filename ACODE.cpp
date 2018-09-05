#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
string s;
int len;
long long cal(int i,vector<long long>& dp){
    if(dp[i]==-1){
        if(s[i]!='0'){
            if((s[i]-'0')*10 + (s[i+1]-'0')<=26)
                dp[i]=cal(i+1,dp)+cal(i+2,dp);
            else
                dp[i]=cal(i+1,dp);
        }
        else return 0;
    }
    if(s[i]!='0')
        return dp[i];
    else return 0;
}
int main(void)
{
    while(1){
        cin>>s;
        len=s.length();
        if(s[0]=='0')
            break;
        if(len==1){
            printf("1\n");
            continue;
        }
        vector<long long> dp(len+1,-1);
        dp[len]=1; dp[len-1]=1;
        printf("%lld\n",cal(0,dp));
    }
    return 0;
}

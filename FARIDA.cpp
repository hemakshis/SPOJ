#include <iostream>
#include <stdio.h>
#include <vector>
#define NIL -1
using namespace std;

long cal(int n,long a[],vector<long long>& dp){

}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int w=1;w<=t;w++){
        printf("Case %d: ",w);
        int n;
        scanf("%d",&n);
        long a[n+5];
        for(int i=0;i<n;i++)
            scanf("%ld",&a[i]);
        vector<long long> dp(n+5,NIL);
    }
    return 0;
}

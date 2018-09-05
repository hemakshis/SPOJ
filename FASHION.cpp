#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int i,j,men[n+5],women[n+5],p=0;
        for(i=0;i<n;i++)
            scanf("%d",&men[i]);
        for(j=0;j<n;j++)
            scanf("%d",&women[j]);
        sort(men,men+n);
        sort(women,women+n);
        for(i=0;i<n;i++)
            p+=men[i]*women[i];
        printf("%d\n",p);
    }
    return 0;
}

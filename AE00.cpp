#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(void)
{
    int n;
    scanf("%d",&n);
    int s=floor(sqrt(n));
    //printf("%d",s);
    long int sum=0;
    while(s){
        sum+=n/s;
        //printf("sum=%d s=%d\n",sum,s);
        s--;
    }
    s=floor(sqrt(n));
    sum-=(s-1)*s/2;
    printf("%d",sum);
    return 0;
}

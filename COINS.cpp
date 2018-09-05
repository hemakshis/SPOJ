#include <iostream>
#include <stdio.h>
#include <map>
#define NIL -1
#define MAX 10000000
//#define MAXM 1000000000
//#define lli long long int
using namespace std;
//map<long long int,long long int> memo;
long long int arr[MAX];
long long int n,i,j;
void initialize(){
    for(i=1;i<=MAX;i++)
        arr[i]=NIL;
    //for(j=MAXA+1;j<=MAXM;j++)
      //  memo[j]=NIL;
}
long long int fib(long long int n){
    if(n<=MAX){
        if(arr[n]==NIL){
            if(n<=11)
                arr[n]=n;
            else
                arr[n]=fib(n/2)+fib(n/3)+fib(n/4);
        }
        return arr[n];
    }
    if(n>MAX)
        return fib(n/2)+fib(n/3)+fib(n/4);
}

int main(void)
{
    initialize();
    while(scanf("%lld",&n)!=EOF)
        printf("%lld\n",fib(n));
    return 0;
}

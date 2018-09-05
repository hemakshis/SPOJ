#include <stdio.h>
#include <iostream>
#define scn(w) scanf("%d",&w)
#define prf(z) printf("%d",z)
int n,squares;
int main()
{
    while(1){
        scn(n);
        if(n==0)
            return 0;
        squares=0;
        while(n){
            squares+=n*n;
            n--;
        }
        prf(squares);
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <iostream>
#define scn(w) scanf("%d",&w)
#define prf(z) printf("%d",z)
int x,y;
int main()
{
    int t;
    scn(t);
    while(t--){
        scn(x);
        scn(y);
        if(x==y){
            if(x%2==0)
                prf(2*x);
            else prf(2*x-1);
        }
        else if(x-y==2){
            if(y%2==0)
                prf(2*y+2);
            else if(y%2==1)
                prf(2*y+1);
        }
        else printf("No Number");
        printf("\n");
    }
    return 0;
}

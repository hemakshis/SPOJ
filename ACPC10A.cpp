#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
float r1,r2,gp1,a1,a2,a3,d,ap,gp;
int c;
int main()
{
    while(1){
        cin>>a1>>a2>>a3;
        //cout<<a1<<" "<<a2<<" "<<a3<<endl;
        if(a1==0 && a2==0 && a3==0)
            return 0;
        if(a2-a1==a3-a2){
            printf("AP ");
            d=a2-a1;
            ap=a3+d;
            c=(int)ap;
            printf("%d",c);
            printf("\n");
            continue;
        }
        r1=a2/a1;
        r2=a3/a2;
        //printf("r1=%e r2=%e\n",r1,r2);
        if(r1==r2 && (r1>1 || r1<-1)){
            printf("GP ");
            gp=a3*r1;
            c=(int)gp;
            printf("%d",c);
            printf("\n");
            continue;
        }
        if(r1<1 && r1>-1 && r1!=0){
            gp1=a3*r1;
            printf("GP ");
            c=(int)gp1;
            printf("%d\n",c);
            continue;
        }
    }
    return 0;
}


#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char sum[105],diff[105],num1[105],num2[105];
short int ls,ld,i,j,k,rem,quo,dvnd,ln1,ln2,w,borrow;

void addition(){
    i=ls-1;k=0;j=ld-1;
    while(i>=0 && j>=0){
        w=sum[i]-'0'+diff[j]-'0';
        w=w+num1[k]-'0';
        if(w>=10){
            num1[k+1]=1+'0';
            num1[k]=w+'0'-10;
        }
        else num1[k]=w+'0';
        k++;
        i--;
        j--;
    }
    if(i<0 && num1[k]!='0')
          k++;
    while(i>=0){
        w=sum[i]-'0';
        w=w+num1[k]-'0';
        if(w>=10){
            num1[k+1]=1+'0';
            num1[k]=w+'0'-10;
        }
        else num1[k]=w+'0';
        k++;
        i--;
    }

}

void subtraction(){
    i=ls-1;j=0;k=0;
    borrow=0;
    while(i>=0 && j<ln1){
        w=(sum[i]-'0')-(num1[j]-'0')-borrow;
        if(w<0){
            w+=10;
            num2[k]=w+'0';
            borrow=1;
        }
        else{
            num2[k]=w+'0';
            borrow=0;
        }
        i--;
        k++;
        j++;
    }
    while(i>=0){
        w=sum[i]-'0'-borrow;
        if(w<0){
            w+=10;
            num2[k]=w+'0';
            borrow=1;
        }
        else{
            num2[k]=w+'0';
            borrow=0;
        }
        i--;
        k++;
    }
}

void division(){
    rem=0;
    for(i=ln1-1;i>=0;i--){
        dvnd=rem*10+num1[i]-'0';
        rem=dvnd%2;
        quo=dvnd/2;
        num1[i]=quo+'0';
    }
    while(num1[k]=='0')
        k--;
    if(k<0){
        k++;
        num1[k]='0';
    }
}

int main(void){
    int t=10;
    while(t--){
        scanf("%s",sum);
        scanf("%s",diff);
        ls=strlen(sum);
        ld=strlen(diff);
        for(int i=0;i<105;i++){
            num1[i]='0';
            num2[i]='0';
        }
        addition();
        ln1=k+1;
        division();
        while(k>=0){
            printf("%c",num1[k]);
            k--;
        }
        printf("\n");
        subtraction();
        while(num2[k]=='0')
            k--;
        if(k<0){
            k++;
            num2[k]='0';
        }
        while(k>=0){
            printf("%c",num2[k]);
            k--;
        }
        printf("\n");
    }
}

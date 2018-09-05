#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

void add(char* s){
    int w=0,k;
    char ans[1000];
    for(int i=0;i<1000;i++)
        ans[i]='0';
    //cout<<"error in add1"<<endl;
    for(int i=strlen(s)-1;i>=0;i--){
        k=(s[i]-'0')+(s[i]-'0');
        k=k+ans[w]-'0';
        if(k>=10){
            ans[w+1]=1+'0';
            //cout<<ans[w]<<" "<<ans[w+1]<<endl;
            ans[w]=k-10+'0';
        }
        else ans[w]=k+'0';
        //cout<<"error in add2"<<endl;
        w++;
    }
    w++;
    //cout<<ans[0]<<" "<<ans<<endl;
    if(ans[0]>='2')
        ans[0]=ans[0]-2;
    else{
        int i=1;
        while(ans[i]<'1'){
            i++;
        }
        //cout<<ans[i]<<endl;
        ans[i]=ans[i]-1;
        i--;
        //cout<<ans[i]<<" "<<i<<endl;
        while(i>=1){
            ans[i]='9';
            i--;
        }
        ans[0]=ans[0]-'0'+10;
        ans[0]=ans[0]-2;
        ans[0]=ans[0]+'0';
    }
    //cout<<"w="<<w<<endl;
    int len=w;
    while(ans[len]=='0')
        len--;
    ans[w]='\0';
    //cout<<"error in add3"<<endl;
    for(int i=len;i>=0;i--)
        printf("%c",ans[i]);
    printf("\n");
}

int main(void)
{
    char s[1000];
    while(cin>>s){
        //cout<<"error in while"<<endl;
        if(strlen(s)==1 && s[0]=='1'){
            printf("1\n");
            continue;
        }
        else
            add(s);
    }
    return 0;
}

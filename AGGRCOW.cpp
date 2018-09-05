#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#define MAX 1000000000
using namespace std;

long int check(int n,int c,long int x,long int a[]){
    long int prev=a[0],dist=0;
    long int curr,counter=1,minVal=LONG_MAX;
    for(int i=1;i<n;i++){
        curr=a[i];
        if(curr-prev>=x){
            //cout<<"prev = "<<prev<<" curr = "<<curr<<endl;
            minVal=min(minVal,curr-prev);
            prev=curr;
            counter++;
            //cout<<"minVal = "<<minVal<<endl;
            dist=0;
        }
        else dist+=curr-prev;
    }
    if(counter>=c)
        return minVal;
    else return -1;
}

long int bst(int n,int c,long int a[]){
    long int st=1,en=MAX;
    long int mid,temp=0,ans=INT_MIN;
    while(st<=en){
        mid=(st+en)/2;
        //cout<<"val send = "<<a[mid]<<endl;
        temp=check(n,c,mid,a);
        if(temp>0){
            if(ans<temp)
                ans=temp;
            st=mid+1;
        }
        else en=mid-1;
    }
    return ans;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,c;
        scanf("%d%d",&n,&c);
        long int a[n+5];
        for(int i=0;i<n;i++)
            scanf("%ld",&a[i]);
        sort(a,a+n);
        printf("%ld\n",bst(n,c,a));
    }
    return 0;
}

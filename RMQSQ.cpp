#include <iostream>
#include <stdio.h>
#include <limits.h>
#define MAX 1000000
using namespace std;
long segTree[MAX],a[MAX];
void builtSegTree(int node,int st,int en){
    if(st==en){
        segTree[node]=a[st];
        //cout<<"segTree = "<<segTree[node]<<" node = "<<node<<" a[st] = "<<a[st]<<" st = "<<a[st]<<endl;
    }
    else{
        int mid=(st+en)/2;
        builtSegTree(2*node,st,mid);
        builtSegTree(2*node+1,mid+1,en);
        segTree[node]=min(segTree[2*node],segTree[2*node+1]);
    }
}
long queryTree(int node,int st,int en,int l,int r){
    if(r<st || l>en){
        return INT_MAX;
    }
    if(st>=l && r>=en){
        return segTree[node];
    }
    else{
        int mid=(st+en)/2;
        long q1=queryTree(2*node,st,mid,l,r);
        long q2=queryTree(2*node+1,mid+1,en,l,r);
        return min(q1,q2);
    }
}
int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%ld",&a[i]);
    builtSegTree(1,0,n-1);
    /*
    for(int i=1;i<=2*n+1;i++)
        cout<<segTree[i]<<" ";
    */
    int q,i,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&i,&j);
        printf("%ld\n",queryTree(1,0,n-1,i,j));
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 100000
#define MAX_PRM 1000009
using namespace std;
int lazy[MAX],segTree[MAX],a[MAX];
bool isPrime[MAX_PRM];
void initialize(){
    for(int i=0;i<MAX;i++){
        segTree[i]=0;
        a[i]=0;
        lazy[i]=0;
    }
}
void sieve(){
    memset(isPrime,true,sizeof(isPrime));
    for(int i=2;i*i<=MAX_PRM;i++){
        if(isPrime[i]){
            for(int j=i*2;j<=MAX_PRM;j+=i)
                isPrime[j]=false;
        }
    }
}
void buildTree(int node,int st,int en){
    if(st==en){
        if(isPrime[a[st]]==true)
            segTree[node]=1;
        else segTree[node]=0;
    }
    else{
        int mid=(st+en)/2;
        buildTree(2*node,st,mid);
        buildTree(2*node+1,mid+1,en);
        segTree[node]=segTree[2*node]+segTree[2*node+1];
    }
}
void updateTree(int node,int st,int en,int l,int r,int v){
    if(lazy[node]!=0){
            segTree[node]=(en-st+1)*isPrime[lazy[node]];
            if(st!=en){
                lazy[2*node]=lazy[node];
                lazy[2*node+1]=lazy[node];
            }
            lazy[node]=0;
    }
    if(st>en || r<st || en<l)
        return;
    if(l<=st && en<=r){
        segTree[node]=(en-st+1)*isPrime[lazy[node]];
        if(st!=en){
            lazy[2*node]=v;
            lazy[2*node+1]=v;
        }
        return;
    }
    int mid=(st+en)/2;
    updateTree(2*node,st,mid,l,r,v);
    updateTree(2*node+1,mid+1,en,l,r,v);
    segTree[node]=segTree[2*node]+segTree[2*node+1];
}
int queryTree(int node,int st,int en,int l,int r){
    if(st>en || r<st || en<l)
        return 0;
    if(lazy[node]!=0){
        segTree[node]=(en-st+1)*isPrime[lazy[node]];
        if(st!=en){
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
    if(l<=st && en<=r)
        return segTree[node];
    int mid=(st+en)/2;
    int q1=queryTree(2*node,st,mid,l,r);
    int q2=queryTree(2*node+1,mid+1,en,l,r);
    return q1+q2;
}
int main(void)
{
    int t;
    scanf("%d",&t);
    sieve();
    for(int w=1;w<=t;w++){
        printf("Case %d:\n",w);
        int n,q;
        scanf("%d%d",&n,&q);
        initialize();
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        buildTree(1,0,n-1);
        int x,y,i,v;
        while(q--){
            scanf("%d",&i);
            if(i==1){
                scanf("%d%d",&x,&y);
                printf("%d\n",queryTree(1,0,n-1,x-1,y-1));
            }
            else{
                scanf("%d%d%d",&x,&y,&v);
                updateTree(1,0,n-1,x-1,y-1,v);
            }
        }
    }
    return 0;
}

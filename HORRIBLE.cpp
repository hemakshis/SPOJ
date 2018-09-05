#include <iostream>
#include <stdio.h>
#define MAX 1000000
using namespace std;
/*
int i,p,q;
long v;
long long int sum1=0,sum2=0;
long long int BIT[MAX];
int t;
int n,c;

void initialize(){
    for(int i=0;i<MAX;i++)
            BIT[i]=0;
}

void update(int idx,long int val){
    while(idx<=n){
        BIT[idx]+=val;
        idx+= (-idx & idx);
    }
}

long long int getSum(int idx){
    long long int sum=0;
    while(idx>0){
        sum+=BIT[idx];
        idx-= (-idx & idx);
    }
    return sum;
}

int main(void)
{
    scanf("%d",&t);
    while(t--){
        initialize();
        scanf("%d%d",&n,&c);
        while(c--){
            scanf("%d",&i);
            sum1=0;sum2=0;
            if(i==0){
                scanf("%d%d%ld",&p,&q,&v);
                for(int j=p;j<=q;j++)
                    update(j,v);
            }
            else{
                scanf("%d%d",&p,&q);
                sum1=getSum(p-1);
                sum2=getSum(q);
                printf("%lld\n",sum2-sum1);
            }
        }
    }
    return 0;
}
*/
long long int n,c,p,q;
long long int v;
long long int segTree[MAX],lazy[MAX];
void initialize(){
    for(long long  int i=0;i<MAX;i++){
        segTree[i]=0;
        lazy[i]=0;
    }
}
void updateRange(long long int node,long long int st,long long int en,long long int l,long long r,long long int val){
    if(lazy[node]!=0){
        segTree[node]+=(en-st+1)*lazy[node];
        if(st!=en){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(st>en || en<l || st>r)
        return;
    if(st>=l && r>=en){
        segTree[node]+=(en-st+1)*val;
        if(st!=en){
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    long long int mid=(st+en)/2;
    updateRange(2*node,st,mid,l,r,val);
    updateRange(2*node+1,mid+1,en,l,r,val);
    segTree[node]=segTree[2*node]+segTree[2*node+1];
}
long long int queryRange(long long int node,long long int st,long long int en,long long int l,long long int r){
    if(st>en || en<l || st>r)
        return 0;
    if(lazy[node]!=0){
        segTree[node]+=(en-st+1)*lazy[node];
        if(st!=en){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(st>=l && r>=en)
        return segTree[node];
    long long int mid=(st+en)/2;
    long long int p1=queryRange(2*node,st,mid,l,r);
    long long int p2=queryRange(2*node+1,mid+1,en,l,r);
    return p1+p2;
}
int main(void)
{
    long long int t;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&c);
        initialize();
        while(c--){
            int i;
            scanf("%d",&i);
            if(i==0){
                scanf("%lld%lld%lld",&p,&q,&v);
                updateRange(1,1,n,p,q,v);
            }
            else{
                scanf("%lld%lld",&p,&q);
                printf("%lld\n",queryRange(1,1,n,p,q));
            }
        }
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <cmath>
#define MAX 1000000
using namespace std;
typedef long long int ll;
typedef long int li;
ll segTree[MAX],lazy[MAX],a[MAX];
void initialize(){
    for(li i=0;i<MAX;i++){
        segTree[i]=0;
        lazy[i]=0;
        a[i]=0;
    }
}
void updateRange(li node,li st,li en,li l,li r, li idx){
    if(lazy[node]!=0){
        segTree[node]=(en-st+1)*lazy[node];
        if(st!=en){
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
    if(st>en || st>r || l>en)
        return;
    if(st<=l && r<=en){
        segTree[node]=floor(sqrt(a[idx]));
        if(st!=en){
            lazy[2*node]=floor(sqrt(a[idx]));
            lazy[2*node+1]=floor(sqrt(a[idx]));
        }
        return;
    }
    li mid=(st+en)/2;
    updateRange(2*node,st,mid,l,r,idx);
    updateRange()
}
int main(void)
{

    return 0;
}

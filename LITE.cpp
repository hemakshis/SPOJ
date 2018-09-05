#include <iostream>
#include <stdio.h>
#define MAX 1000000
using namespace std;
int segTree[MAX],lazy[MAX],a[MAX];
void initialize(){
    for(int i=0;i<MAX;i++){
        segTree[i]=0;
        lazy[i]=0;
    }
}
void updateRange(int node,int st,int en,int l,int r){
    if(lazy[node]!=0){
        //cout<<"BEFORE segTree["<<node<<"] = "<<segTree[node]<<" lazy["<<node<<"] = "<<lazy[node]<<endl;
        segTree[node]=en-st+1-segTree[node];
        if(st!=en){
            lazy[2*node]=!lazy[2*node];
            lazy[2*node+1]=!lazy[2*node+1];
            //cout<<"lazy["<<2*node<<"] = "<<lazy[2*node]<<" lazy["<<2*node+1<<"] = "<<lazy[2*node+1]<<endl;
        }
        lazy[node]=0;
        //cout<<"AFTER segTree["<<node<<"] = "<<segTree[node]<<" lazy["<<node<<"] = "<<lazy[node]<<endl;
    }
    if(st>en || r<st || en<l)
        return;
    if(st>=l && en<=r){
        //cout<<"BEFORE segTree["<<node<<"] = "<<segTree[node]<<" lazy["<<node<<"] = "<<lazy[node]<<endl;
        segTree[node]=en-st+1-segTree[node];
        if(st!=en){
            lazy[2*node]=!lazy[2*node];
            lazy[2*node+1]=!lazy[2*node+1];
            //cout<<"lazy["<<2*node<<"] = "<<lazy[2*node]<<" lazy["<<2*node+1<<"] = "<<lazy[2*node+1]<<endl;
        }
        //cout<<"AFTER segTree["<<node<<"] = "<<segTree[node]<<" lazy["<<node<<"] = "<<lazy[node]<<endl;
        return;
    }
    else{
        int mid=(st+en)/2;
        updateRange(2*node,st,mid,l,r);
        updateRange(2*node+1,mid+1,en,l,r);
        segTree[node]=segTree[2*node]%(en-st+1)+segTree[2*node+1]%(en-st+1);
        //cout<<"final "<<"segTree["<<node<<"] = "<<segTree[node]<<endl;
    }
}
int queryRange(int node,int st,int en,int l,int r){
    if(st>en || r<st || en<l)
        return 0;
    if(lazy[node]!=0){
        //cout<<"BEFORE segTree["<<node<<"] = "<<segTree[node]<<" lazy["<<node<<"] = "<<lazy[node]<<endl;
        segTree[node]=en-st+1-segTree[node];
        if(st!=en){
            lazy[2*node]=!lazy[2*node];
            lazy[2*node+1]=!lazy[2*node+1];
            //cout<<"lazy["<<2*node<<"] = "<<lazy[2*node]<<" lazy["<<2*node+1<<"] = "<<lazy[2*node+1]<<endl;
        }
        lazy[node]=0;
        //cout<<"AFTER segTree["<<node<<"] = "<<segTree[node]<<" lazy["<<node<<"] = "<<lazy[node]<<endl;
    }
    if(l<=st && en<=r)
        return segTree[node];
    else{
        int mid=(st+en)/2;
        int q1=queryRange(2*node,st,mid,l,r);
        int q2=queryRange(2*node+1,mid+1,en,l,r);
        return q1+q2;
    }
}
int main(void)
{
    int n,m;
    scanf("%d%d",&n,&m);
    int q,x,y;
    while(m--){
        scanf("%d",&q);
        if(q){
            scanf("%d%d",&x,&y);
            printf("%d\n",queryRange(1,0,n-1,x-1,y-1));
        }
        else{
            scanf("%d%d",&x,&y);
            updateRange(1,0,n-1,x-1,y-1);
        }
    }
    return 0;
}

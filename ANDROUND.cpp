#include <iostream>
#include <stdio.h>
#define MAX 100000
#define MAX_TREE 1000000
using namespace std;
long k,segTree[MAX_TREE],a[MAX];
int n;

void buildTree(int node,int st,int en){
    if(st==en){
        segTree[node]=a[st];
        //cout<<"segTree["<<node<<"] = "<<segTree[node]<<" a["<<st<<"] = "<<a[st]<<endl;
    }
    else{
        int mid=(st+en)/2;
        buildTree(2*node,st,mid);
        buildTree(2*node+1,mid+1,en);
        segTree[node]=segTree[2*node] & segTree[2*node+1];
        //cout<<"segTree["<<node<<"] = "<<segTree[node]<<endl;
    }
}
long queryTree(int node,int st,int en,int l,int r){
    if(st>en || r<st || en<l)
        return -1;
    else if(l<=st && en<=r){
        return segTree[node];
    }
    else{
        int mid=(st+en)/2;
        long q1=queryTree(2*node,st,mid,l,r);
        long q2=queryTree(2*node+1,mid+1,en,l,r);
        if(q1==-1 && q2!=-1)
            return q2;
        else if(q2==-1 && q1!=-1)
            return q1;
        else return q1 & q2;
    }
}
int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%ld",&n,&k);
        for(int i=n-1;i<=2*(n-1);i++){
            scanf("%ld",&a[i]);
            if(i>=n){
                a[i-n]=a[i];
            }
            if(i<2*(n-1)){
                a[i+n]=a[i];
            }
        }
        buildTree(1,0,3*(n-1));
        for(int i=n-1;i<=2*(n-1);i++){
            if(k<=(n-1)/2){
                a[i]=queryTree(1,0,3*(n-1),i-k,i+k);
            }
            else{
                a[i]=segTree[1];
            }
        }
        for(int i=n-1;i<=2*(n-1);i++){
            printf("%ld ",a[i]);
        }
        printf("\n");
    }
    return 0;
}

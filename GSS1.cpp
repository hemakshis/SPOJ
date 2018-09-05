#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;

const int N=1e5+5;
long a[N];
struct Node
{
    long l; //left sum
    long r; //right sum
    long f; //full sum
    long m; //max sum
} segTree[N*6],ans,MIN;

void initialize(){
    for(int i=0;i<N;i++)
        a[i]=0;
    for(int i=0;i<N*6;i++){
        segTree[i].f=0;
        segTree[i].l=0;
        segTree[i].r=0;
        segTree[i].m=0;
    }
    ans.l=0; ans.r=0; ans.f=0; ans.m=0;
}

void mergeNode(int node){
    segTree[node].f=segTree[2*node].f+segTree[2*node+1].f;
    segTree[node].l=max(segTree[2*node].l,segTree[2*node].f+segTree[2*node+1].l);
    segTree[node].r=max(segTree[2*node+1].r,segTree[2*node+1].f+segTree[2*node].r);
    segTree[node].m=max(segTree[2*node].r+segTree[2*node+1].l,max(segTree[2*node].m,segTree[2*node+1].m));
}

struct Node queryNode(struct Node q1,struct Node q2){
    struct Node q;
    q.f=q1.f+q2.f;
    q.l=max(q1.l,q1.f+q2.l);
    q.r=max(q2.r,q2.f+q1.r);
    q.m=max(q1.r+q2.l,max(q1.m,q2.m));
    return q;
}

bool operator==(struct Node q1,struct Node q2){
    if(q1.l==q2.l && q1.r==q2.r && q1.f==q2.f && q1.m==q2.m)
        return 1;
    else return 0;
}

void buildTree(int node,int st,int en){
    if(st==en){
        //cout<<node<<" = ";
        segTree[node].f=segTree[node].m=segTree[node].l=segTree[node].r=a[st];
        //cout<<"("<<segTree[node].l<<" "<<segTree[node].r<<" "<<segTree[node].m<<" "<<segTree[node].f<<") ";
    }
    else{
        int mid=(st+en)/2;
        buildTree(2*node,st,mid);
        buildTree(2*node+1,mid+1,en);
        mergeNode(node);
        //cout<<node<<" = ";
        //cout<<"("<<segTree[node].l<<" "<<segTree[node].r<<" "<<segTree[node].m<<" "<<segTree[node].f<<") ";
    }
}

struct Node queryTree(int node,int st,int en,int l,int r){
    if(st>=l && r>=en)
        return segTree[node];
    else if(st>en || l>en || st>r)
        return MIN;
    else{
        int mid=(st+en)/2;
        struct Node q1=queryTree(2*node,st,mid,l,r);
        struct Node q2=queryTree(2*node+1,mid+1,en,l,r);
        if(q1==MIN)
            return q2;
        else if(q2==MIN)
            return q1;
        return queryNode(q1,q2);
    }
}

//below code is for GSS3 only

void updateTree(int node,int st,int en,int pos,int val){
    if(st==en && st==pos){
        segTree[node].f=segTree[node].m=segTree[node].l=segTree[node].r=val;
    }
    else if(st>en || st>pos || pos>en)
        return;
    else{
        int mid=(st+en)/2;
        updateTree(2*node,st,mid,pos,val);
        updateTree(2*node+1,mid+1,en,pos,val);
        mergeNode(node);
    }
}

int main(void)
{
    MIN.f=LONG_MIN;
    MIN.l=LONG_MIN;
    MIN.r=LONG_MIN;
    MIN.m=LONG_MIN;
    initialize();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%ld",&a[i]);
    buildTree(1,0,n-1);
    int m,q,x,y;
    scanf("%d",&m);
    while(m--){
        scanf("%d%d%d",&q,&x,&y);
        if(q==0){
            x--;
            updateTree(1,0,n-1,x,y);
        }
        else{
            x--; y--;
            ans=queryTree(1,0,n-1,x,y);
            printf("%ld\n",ans.m);
        }
    }
    return 0;
}
/*
10
-1 9 2 6 -4 3 5 2 -6 1
2
4 7
1 10
*/

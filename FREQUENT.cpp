#include <iostream>
#include <stdio.h>
#include <utility>
using namespace std;

const int N=1e5+7;
int a[N];
struct Node
{
    pair<int,int> l;  //element_value and element_count
    pair<int,int> r;
    pair<int,int> m;
} segTree[N*6];

void initialize(){
    for(int i=0;i<N;i++)
        a[i]=INT_MIN;
    for(int i=0;i<N*6;i++){
        segTree[i].l.first=-1; segTree[i].l.second=-1;
        segTree[i].r.first=-1; segTree[i].r.second=-1;
        segTree[i].m.first=-1; segTree[i].m.second=-1;
    }
}

void mergeNode(int node){
    segTree[node].l.first=
}

void buildTree(int node,int st,int en){
    if(st==en){
        segTree[node].l.first=a[st]; segTree[node].l.second=1;
        segTree[node].r.first=a[st]; segTree[node].r.second=1;
        segTree[node].m.first=a[st]; segTree[node].m.second=1;
    }
    else{
        int mid=(st+en)/2;
        buildTree(2*node,st,mid);
        buildTree(2*node+1,mid+1,en);
        mergeNode(node);
    }
}

int main(void)
{
    while(1){
        initialize();
        int n,q;
        scanf("%d",&n);
        if(n==0)
            break;
        scanf("%d",&q);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int u,v;
        while(q--){
            scanf("%d%d",&u,&v);
        }
    }
    return 0;
}

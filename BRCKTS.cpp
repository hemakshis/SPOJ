#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;
const int N=5e5;
int a[N];
char c[N];
struct Node
{
    int open;
    int close;
} segTree[N*6];

void initialize(){
    for(int i=0;i<N;i++){
        a[i]=-1;
        c[i]='\0';
    }
    for(int i=0;i<N*6;i++){
        segTree[i].open=0;
        segTree[i].close=0;
    }
}

void mergeNode(int node){
    segTree[node].open=segTree[2*node+1].open+segTree[2*node].open-min(segTree[2*node].open,segTree[2*node+1].close);
    segTree[node].close=segTree[2*node].close+segTree[2*node+1].close-min(segTree[2*node].open,segTree[2*node+1].close);
}

void buildTree(int node,int st,int en){
    if(st==en){
        if(a[st]==1){
            segTree[node].open=1;
            segTree[node].close=0;
        }
        else{
            segTree[node].open=0;
            segTree[node].close=1;
        }
    }
    else{
        int mid=(st+en)/2;
        buildTree(2*node,st,mid);
        buildTree(2*node+1,mid+1,en);
        mergeNode(node);
    }
}

void updateTree(int node,int st,int en,int pos){
    if(st==en && st==pos){
        a[st]=!a[st];
        if(a[st]==1){
            segTree[node].open=1;
            segTree[node].close=0;
        }
        else{
            segTree[node].open=0;
            segTree[node].close=1;
        }
        return;
    }
    else if(st>en || st>pos || pos>en)
        return;
    else{
        int mid=(st+en)/2;
        updateTree(2*node,st,mid,pos);
        updateTree(2*node+1,mid+1,en,pos);
        mergeNode(node);
    }
}

int main(void)
{
    const int t=10;
    for(int w=1;w<=t;w++){
        initialize();
        int n;
        scanf("%d",&n);
        scanf("%s",&c);
        for(int i=0;i<n;i++){
            if(c[i]=='(')
                a[i]=1;
            else a[i]=0;
        }
        int m,q;
        buildTree(1,0,n-1);
        scanf("%d",&m);
        printf("Test %d:\n",w);
        while(m--){
            scanf("%d",&q);
            if(q==0){
                if(segTree[1].open==segTree[1].close && segTree[1].open==0)
                    printf("YES\n");
                else printf("NO\n");
            }
            else{
                updateTree(1,0,n-1,q-1);
            }
        }
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <string.h>
#include <limits.h>
using namespace std;
int euleridx,euler[2100],level[2100],firstOccurence[1005],segTree[5000];
vector<int> graph[1005];
void initialize(){
    for(int i=0;i<1005;i++){
        graph[i].clear();
        firstOccurence[i]=-1;
    }
    for(int i=0;i<5000;i++){
        segTree[i]=-1;
    }
    for(int i=0;i<2100;i++){
        euler[i]=-1;
        level[i]=INT_MAX;
    }
    euleridx=0;
}

void eulerTour(int i,int l){
    euler[euleridx]=i;
    level[euleridx]=l;
    euleridx++;
    if(firstOccurence[i]==-1){
        firstOccurence[i]=euleridx;
    }
    if(graph[i].empty()){
        return;
    }
    vector<int> :: iterator it;
    for(it=graph[i].begin();it!=graph[i].end();it++){
        eulerTour(*it,l+1);
        euler[euleridx]=i;
        level[euleridx]=l;
        euleridx++;
    }
}

void buildTree(int node,int st,int en){
    if(st==en){
        segTree[node]=st;
        //cout<<segTree[node]<<" ";
    }
    else{
        int mid=(st+en)/2;
        buildTree(2*node,st,mid);
        buildTree(2*node+1,mid+1,en);
        if(level[segTree[2*node]]<=level[segTree[2*node+1]])
            segTree[node]=segTree[2*node];
        else segTree[node]=segTree[2*node+1];
        //cout<<segTree[node]<<" ";
    }
}

int queryTree(int node,int st,int en,int l,int r){
    if(st>r || en<l)
        return -1;
    else if(l<=st && en<=r)
        return segTree[node];
    else{
        int mid=(st+en)/2;
        int q1=queryTree(2*node,st,mid,l,r);
        int q2=queryTree(2*node+1,mid+1,en,l,r);
        if(q1==-1)
            return q2;
        else if(q2==-1)
            return q1;
        else if(level[q1]<=level[q2])
            return q1;
        else return q2;
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int f=1;f<=t;f++){
        initialize();
        int m,n,z;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&m);
            while(m--){
               scanf("%d",&z);
                graph[i].push_back(z);
            }
        }
        eulerTour(1,0);
        /*
        for(int w=0;w<2*n-1;w++){
            cout<<euler[w]<<" ";
        }
        cout<<endl;
        for(int w=0;w<2*n-1;w++){
            cout<<level[w]<<" ";
        }
        cout<<endl;
        for(int w=1;w<=n;w++){
            cout<<firstOccurence[w]<<" ";
        }
        cout<<endl;
        */
        buildTree(1,0,2*n-2);
        //cout<<endl;
        int u,v,q,ans;
        scanf("%d",&q);
        printf("Case %d:\n",f);
        while(q--){
            scanf("%d%d",&u,&v);
            ans=euler[queryTree(1,0,2*n-2,min(firstOccurence[min(u,v)]-1,firstOccurence[max(u,v)]-1),max(firstOccurence[min(u,v)]-1,firstOccurence[max(u,v)]-1))];
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
1
13
3 2 3 4
0
3 5 6 7
0
0
2 8 9
2 10 11
0
0
2 12 13
0
0
0
*/

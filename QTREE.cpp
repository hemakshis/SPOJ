#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits.h>
#include <utility>
using namespace std;
const int N=1e5;
const int LN=20;
vector<pair<int,int> > graph[N];
vector<pair<int,int> > edge(N);
int ancestors[LN][N],subtreeSize[N],depth[N],chainNo,chainHead[N],chainInd[N],posInBase[N],baseArray[N],ptr;
int segTree[6*N];
void initialize(){
    for(int i=0;i<N;i++){
        graph[i].clear();
        subtreeSize[i]=-1;
        depth[i]=-1;
        chainHead[i]=-1;
        chainInd[i]=-1;
        posInBase[i]=-1;
        baseArray[i]=-1;
        for(int j=0;j<LN;j++) ancestors[j][i]=-1;
    }
    for(int i=0;i<6*N;i++)
        segTree[i]=0;
    edge.clear();
    chainNo=0;
    ptr=0;
}
void dfs(int u,int p,int lvl){          // subtreeSize, depth and 2^k-th ancestor setup
    depth[u]=lvl;
    subtreeSize[u]=1;
    for(int i=1;i<LN;i++){
        ancestors[i][u]=ancestors[i-1][ancestors[i-1][u]];
    }
    for(int i=0;i<graph[u].size();i++){
        if(graph[u][i].first!=p){
            ancestors[0][graph[u][i].first]=u;
            dfs(graph[u][i].first,u,lvl+1);
            subtreeSize[u]+=subtreeSize[graph[u][i].first];
        }
    }
}

int lca(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);
    for(int i=LN-1;i>=0;i--){
        if(depth[u]-(1<<i)>=depth[v])
            u=ancestors[i][u];
    }
    if(u==v) return u;
    for(int i=LN-1;i>=0;i--){
        if(ancestors[i][u]!=ancestors[i][v]){
            u=ancestors[i][u];
            v=ancestors[i][v];
        }
    }
    return ancestors[0][u];
}

void hld(int u,int c,int p){
    if(chainHead[chainNo]==-1){
        chainHead[chainNo]=u;
    }
    chainInd[u]=chainNo;
    posInBase[u]=ptr;
    baseArray[ptr++]=c;
    int sc=N-1;
    int cst;
    for(int i=0;i<graph[u].size();i++){
        if(graph[u][i].first!=p){
            if(sc==N-1 || subtreeSize[sc]<subtreeSize[graph[u][i].first]){
                sc=graph[u][i].first;
                cst=graph[u][i].second;
            }
        }
    }
    if(sc!=N-1){
        hld(sc,cst,u);
    }
    for(int i=0;i<graph[u].size();i++){
        if(graph[u][i].first!=p && graph[u][i].first!=sc){
            chainNo++;
            hld(graph[u][i].first,graph[u][i].second,u);
        }
    }
}

void buildTree(int node,int st,int en){
    if(st>en)
        return;
    if(st==en){
        segTree[node]=baseArray[st];
        return;
    }
    else{
        int mid=(st+en)/2;
        buildTree(2*node,st,mid);
        buildTree(2*node+1,mid+1,en);
        segTree[node]=max(segTree[2*node],segTree[2*node+1]);
    }
}

int queryTree(int node,int st,int en,int l,int r){
    if(l<=st && en<=r)
        return segTree[node];
    else if(st>en || en<l || r<st)
        return -1;
    else{
        int mid=(st+en)/2;
        int q1=queryTree(2*node,st,mid,l,r);
        int q2=queryTree(2*node+1,mid+1,en,l,r);
        return max(q1,q2);
    }
}

void updateTree(int node,int st,int en,int pos,int val){
    if(st>en || en<pos || pos<st)
        return;
    else if(st==en && st==pos){
        segTree[node]=val;
        return;
    }
    else{
        int mid=(st+en)/2;
        updateTree(2*node,st,mid,pos,val);
        updateTree(2*node+1,mid+1,en,pos,val);
        segTree[node]=max(segTree[2*node],segTree[2*node+1]);
    }
}

int queryUp(int u,int v){
    if(u==v) return 0;
    int uchain,vchain=chainInd[v],ans=-1;
    while(1){
        uchain=chainInd[u];
        if(uchain==vchain){
            if(u==v)
                break;
            ans=max(ans,queryTree(1,0,ptr-1,posInBase[v]+1,posInBase[u]));
            break;
        }
        ans=max(ans,queryTree(1,0,ptr-1,posInBase[chainHead[uchain]],posInBase[u]));
        u=chainHead[uchain];
        u=ancestors[0][u];
    }
    return ans;
}

int query(int u,int v){
    int l=lca(u,v);
    int q1=queryUp(u,l);
    int q2=queryUp(v,l);
    return max(q1,q2);
}

void update(pair<int,int>& x,int val){
    int u=x.first, v=x.second;
    if(depth[u]>depth[v])
        updateTree(1,0,ptr-1,posInBase[u],val);
    else updateTree(1,0,ptr-1,posInBase[v],val);
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        initialize();
        int n,a,b,c,x,y,val;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&a,&b,&c);
            graph[a].push_back(make_pair(b,c));
            graph[b].push_back(make_pair(a,c));
            edge[i]=make_pair(a,b);
        }
        ancestors[0][1]=0;
        dfs(1,0,0);
        hld(1,0,0);
        buildTree(1,0,ptr-1);
        char q[100];
        while(1){
            scanf("%s",q);
            if(q[0]=='D')
                break;
            else if(q[0]=='C'){
                scanf("%d%d",&x,&val);
                update(edge[x],val);
            }
            else{
                scanf("%d%d",&x,&y);
                printf("%d\n",query(x,y));
            }
        }
    }
    return 0;
}

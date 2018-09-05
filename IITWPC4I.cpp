#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int N=1e5+7;
int a[N];
vector<pair<long,pair<int,int> > > graph;

bool comp(pair<long,pair<int,int> >& a,pair<long,pair<int,int> >& b) { return a.first<b.first; }

struct unionFind
{
    int n;
    int *r,*p,*mm;
    unionFind(int n){
        this->n=n;
        p=new int[n+1];
        r=new int[n+1];
        mm=new int[n+1];
        for(int i=1;i<=n;i++){
            p[i]=i;
            r[i]=1;
            mm[i]=a[i];
        }
    }
    int Find(int x){
       if(x!=p[x])
            p[x]=Find(p[x]);
       return p[x];
    }
    void Link(int x,int y){
        if(mm[y])
            p[x]=y;
        else if(mm[x])
            p[y]=x;
        else if(r[y]>r[x])
            p[x]=y;
        else p[y]=x;
        if(r[y]==r[x])
            r[y]++;
    }
    void Union(int x,int y){
        Link(Find(x),Find(y));
    }
};

long long kruskal(int n,int m){

    unionFind uf(n);
    long long ans=0;
    sort(graph.begin(),graph.end(),comp);
    int u,v;
    for(int i=1;i<=m;i++){
        u=graph[i].second.first;
        v=graph[i].second.second;
        if(uf.mm[uf.Find(u)]==1 && uf.mm[uf.Find(v)]==1)
            continue;
        else if(uf.Find(u)!=uf.Find(v)){
            ans+=graph[i].first;
            uf.Union(u,v);
        }
    }
    for(int i=1;i<=n;i++){
        if(uf.mm[uf.Find(i)]!=1)
            return -1;
    }
    return ans;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        graph.clear();
        int n,m,u,v;
        long c;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        graph.push_back(make_pair(-1,make_pair(-1,-1)));
        for(int i=1;i<=m;i++){
            scanf("%d%d%ld",&u,&v,&c);
            graph.push_back(make_pair(c,make_pair(u,v)));
        }
        long long mst=kruskal(n,m);
        if(mst!=-1)
            printf("%lld\n",mst);
        else printf("impossible\n");
    }
    return 0;
}

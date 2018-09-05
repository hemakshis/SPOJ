#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int N=2e4+7;

vector<pair<int,pair<int,int> > > graph;

struct unionFind
{
    int n;
    int *r,*p,*sz;
    unionFind(int n){
        this->n=n;
        p=new int[n+1];
        r=new int[n+1];
        sz=new int[n+1];
        for(int i=1;i<=n;i++){
            p[i]=i;
            r[i]=1;
            sz[i]=0;
        }
    }
    int Find(int x){
       if(x!=p[x])
            p[x]=Find(p[x]);
       return p[x];
    }
    void Link(int x,int y){
        if(r[y]>r[x])
            p[x]=y;
        else p[y]=x;
        if(r[y]==r[x])
            r[y]++;
    }
    void Union(int x,int y){
        Link(Find(x),Find(y));
    }
};

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        graph.clear();
        int n,x,y;
        scanf("%d",&n);
        graph.push_back(make_pair(0,make_pair(-1,-1)));
        for(int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            graph.push_back(make_pair(i,make_pair(x,y)));
        }
        unionFind uf(n);
        int q;
        scanf("%d",&q);
        int r[n]={0};
        pair<int,long long> query[q];
        for(int i=0;i<q;i++){
            query[i].first=-1;
            query[i].second=-1;
        }
        char c;
        int v;
        for(int i=0;i<q;i++){
            cin>>c;
            if(c=='R'){
                scanf("%d",&v);
                query[i].first=1;
                query[i].second=v;
                r[v]=1;
            }
            if(c=='Q'){
                query[i].first=2;
            }
        }
        for(int i=1;i<n;i++){
            if(!r[i]){
                uf.Union(graph[i].second.first,graph[i].second.second);
            }
        }
        for(int i=1;i<=n;i++){
            uf.sz[uf.Find(i)]++;
        }
        vector<int> sizes;
        long long totalDisconnectedPairs=0,tmp;
        for(int i=1;i<=n;i++){
            if(uf.sz[i]){
                sizes.push_back(uf.sz[i]);
            }
        }
        tmp=n;
        for(int i=0;i<sizes.size();i++){
            tmp-=sizes[i];
            totalDisconnectedPairs+=tmp*sizes[i];
        }

        //cout<<"totalDisconnectedPairs = "<<totalDisconnectedPairs<<endl;

        for(int i=q-1;i>=0;i--){
            if(query[i].first==1){
                x=graph[query[i].second].second.first;
                y=graph[query[i].second].second.second;
                totalDisconnectedPairs-=uf.sz[uf.Find(x)]*uf.sz[uf.Find(y)];
                if(uf.r[uf.Find(y)]>uf.r[uf.Find(x)])
                    uf.sz[uf.Find(y)]+=uf.sz[uf.Find(x)];
                else uf.sz[uf.Find(x)]+=uf.sz[uf.Find(y)];
                uf.Union(x,y);
            }
            else{
                query[i].second=totalDisconnectedPairs;
            }
        }
        for(int i=0;i<q;i++){
            if(query[i].first==2)
                printf("%lld\n",query[i].second);
        }
        //printf("\n");
    }
    return 0;
}

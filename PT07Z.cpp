#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <queue>
#include <limits.h>

using namespace std;

const int N=1e5;
vector<int> graph[N];
bool vis[N];

pair<long,long> bfs(int s, vector<int> &d){
    memset(vis,false,sizeof(vis));
    queue<int> q;
    d[s]=0;
    vis[s]=true;
    q.push(s);
    int u,v;
    pair<long,long> p;
    p.first=LONG_MIN;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++){
            v=graph[u][i];
            if(!vis[v]){
                vis[v]=true;
                d[v]=d[u]+1;
                if(p.first<d[v]){
                    p.first=d[v];
                    p.second=v;
                }
                q.push(v);
            }
        }
    }
    return p;
}


int main(void)
{
    int n;
    scanf("%d",&n);
    int x,y;
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> d1(N,0),d2(N,0);
    pair<long,long> s,d;
    s=bfs(0,d1);
    //cout<<s.first<<"\t"<<s.second<<endl;
    d=bfs(s.second,d2);
    //cout<<d.first<<"\t"<<d.second<<endl;
    long ans=d.first;
    printf("%ld\n",ans);
    return 0;
}

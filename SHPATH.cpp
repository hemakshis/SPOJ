#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <utility>
#include <set>
#define MAX 10010
#define INF 2000000
using namespace std;
vector< pair<int,long int> > graph[MAX];
void shpath(int n,int src, int dest){
    vector<long int> dist(n+5,INF);
    //cout<<"src = "<<src<<endl;
    dist[src]=0;
    set< pair<long int,int> > setd;
    setd.insert(make_pair(0,src));
    while(!setd.empty()){
        pair<long int,int> pq = *(setd.begin());
        setd.erase(setd.begin());
        int v = pq.second;
        //cout<<"v = "<<v<<endl;
        vector<pair<int,long int> > :: iterator vp;
        for(vp=graph[v].begin();vp!=graph[v].end();vp++){
            int w=vp->first;
            long int cost=vp->second;
            if(dist[w]>dist[v]+cost){
                if(dist[w]!=INF)
                    setd.erase(setd.find(make_pair(dist[w],w)));
                dist[w]=dist[v]+cost;
                //cout<<"from = "<<v<<" to = "<<w<<" dist = "<<dist[w]<<endl;
                setd.insert(make_pair(dist[w],w));
            }
        }
    }
    /*for(int i=1;i<=n;i++)
        cout<<"from = "<<src<<" to = "<<i<<" dist = "<<dist[i]<<endl;*/
    printf("%ld\n",dist[dest]);
}
int main(void)
{
    int s;
    scanf("%d",&s);
    while(s--){
        for(int i=0;i<MAX;i++)
            graph[i].clear();
        map<string,int> my_map;
        int n;
        scanf("%d",&n);
        string names[n+5];
        for(int i=1;i<=n;i++){
            cin>>names[i];
            my_map[names[i]]=i;
            //cout<<names[i]<<" = "<<my_map[names[i]]<<endl;
            int p;
            scanf("%d",&p);
            while(p--){
                int ngbr;
                long int cost;
                scanf("%d%ld",&ngbr,&cost);
                graph[i].push_back(make_pair(ngbr,cost));
            }
        }
        int r;
        scanf("%d",&r);
        while(r--){
            char name1[15],name2[15];
            scanf("%s\t%s",&name1,&name2);
            shpath(n,my_map[name1],my_map[name2]);
        }
        printf("\n");
    }
    return 0;
}
/*
1
4
gdansk
2
2 1
3 3
bydgoszcz
3
1 1
3 1
4 4
torun
3
1 3
2 1
4 1
warszawa
2
2 4
3 1
2
gdansk warszawa
bydgoszcz warszawa
*/

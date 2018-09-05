#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#define MAX_EDGES 10009
using namespace std;
vector<int> graph[105];
long int no_of_edges;
int n,k,s,d,m;
void initialize(){
    for(int i=0;i<105;i++)
        graph[i].clear();
}
void dfs(bool visited[],int i){
    visited[i]=true;
    //cout<<"visited = "<<i<<endl;
    vector<int> :: iterator ig;
    for(ig=graph[i].begin();ig!=graph[i].end();ig++)
        if(visited[*ig]==false && (*ig)!=0)
            dfs(visited,*ig);
}
void isConnected(){
    bool visited[n+5];
    for(int i=0;i<n+5;i++)
        visited[i]=false;
    int i,q;
    long int odd=0,zero_edge=0;
    int ver,f=0;
    for(int i=1;i<=n;i++){
        if(graph[i].size()==0){
            zero_edge++;
        }
        if(zero_edge==n){
            printf("YES 1\n");
            return;
        }
        if(graph[i].size() & 1){
            odd++;
            if(odd>0 && f==0){
                ver=i;
                f=1;
            }
        }
    }
    if(odd==0){
        for(i=1;i<=n;i++)
            if(graph[i].size()!=0)
                break;
        q=i;
        dfs(visited,i);
    }
    else if(odd==2){
        q=ver;
        dfs(visited,ver);
    }
    else if(odd>2){
        printf("NO\n");
        return;
    }
    for(int j=1;j<=n;j++){
        if(visited[j]==false && graph[j].size()>0){
            printf("NO\n");
            return;
        }
    }
    printf("YES %d\n",q);
    return;
}
int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        initialize();
        no_of_edges=0;
        while(k--){
            scanf("%d%d%d",&s,&d,&m);
            while(m--){
                graph[s].push_back(d);
                graph[d].push_back(s);
                no_of_edges++;
            }
        }
        isConnected();
    }
    return 0;
}

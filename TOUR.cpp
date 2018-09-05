#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
#define MAX 1500
using namespace std;
vector<int> graph[MAX];
bool visited[MAX];
int connected(int src,int dest){
    memset(visited,false,sizeof(visited));
    visited[src]=true;
    queue<int> q;
    q.push(src);
    vector<int> :: iterator ig;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(ig=graph[u].begin();ig!=graph[u].end();ig++){
            int v=*ig;
            if(v==dest)
                return 1;
            else if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
        }
    }
    return 0;
}
int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,ans=0;
        scanf("%d",&n);
        for(int i=0;i<n+5;i++)
            graph[i].clear();
        for(int j=1;j<=n;j++){
            int l;
            scanf("%d",&l);
            while(l!=0){
                int x;
                scanf("%d",&x);
                graph[x].push_back(j);
                l--;
            }
        }
        for(int j=1;j<=n;j++){
            int flag=0,k;
            for(k=1;k<=n;k++){
                if(k!=j){
                    if(connected(j,k)==0){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0 && k==n+1)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
4
3
2 3 2
1 3
0
6
1 5
1 1
1 2
1 2
1 2
1 2
5
2 2 4
1 3
1 1
0
1 1
6
2 2 3
1 3
1 4
2 1 6
1 2
0
*/

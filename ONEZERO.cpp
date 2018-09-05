#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
#define MAX 20005
int parent[MAX];
int value[MAX];
void bfs(int n){
    int current=1;
    parent[current]=0;
    queue<int> que;
    que.push(current);
    while(!que.empty()){
        current=que.front();
        que.pop();
        if(current==0){
            stack<int> st;
            while(parent[current]!=0){
                st.push(value[current]);
                current=parent[current];
            }
            st.push(1);
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
            cout<<endl;
        }
        int temp=10*current+0;
        temp=temp%n;
        if(parent[temp]==-1){
            que.push(temp);
            parent[temp]=current;
            value[temp]=0;
        }
        temp=10*current+1;
        temp=temp%n;
        if(parent[temp]==-1){
            que.push(temp);
            parent[temp]=current;
            value[temp]=1;
        }
    }
}
int main(void)
{
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        int n;
        scanf("%d",&n);
        if(n==1 || n==10){
            cout<<n<<endl;
            continue;
        }
        else if(n==2 || n==5){
            cout<<"10"<<endl;
            continue;
        }
        else if(n==4){
            cout<<"100"<<endl;
            continue;
        }
        else if(n==3){
            cout<<"111"<<endl;
            continue;
        }
        else{
            memset(parent,-1,sizeof(parent));
            bfs(n);
        }
    }
    return 0;
}

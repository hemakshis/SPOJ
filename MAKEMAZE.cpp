#include <iostream>
#include <stdio.h>
#include <utility>
#include <queue>
using namespace std;
int t,m,n,i,j,k,check,r,c,flag;
char maze[25][25];
bool visited[25][25];
pair<int,int> dir[2][2];
pair<int,int> a[2];
void initialize(){
    for(int i=0;i<25;i++){
        for(j=0;j<25;j++){
            visited[i][j]=false;
            maze[i][j]='\0';
        }
    }
}
int bfs(int x,int y){
    queue< pair<int,int> > q;
    q.push(make_pair(x,y));
    visited[x][y]=true;
    while(!q.empty()){
        r=q.front().first;
        c=q.front().second;
        q.pop();
        if(r==a[1].first && c==a[1].second){
            //printf("final r=%d c=%d\n",r,c);
            return 1;
        }
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                r=r+dir[i][j].first;
                c=c+dir[i][j].second;
                if(r>=0 && r<m && c>=0 && c<n && maze[r][c]=='.' && visited[r][c]==false){
                    visited[r][c]=true;
                    q.push(make_pair(r,c));
              //      printf("in condition\n");
                //    printf("r=%d c=%d\n",r,c);
                }
                r=r-dir[i][j].first;
                c=c-dir[i][j].second;
            }
        }
    }
    return 0;
}
int main(void)
{
    scanf("%d",&t);
    dir[0][0].first=1; dir[0][0].second=0; //right
    dir[0][1].first=-1; dir[0][1].second=0; //left
    dir[1][0].first=0; dir[1][0].second=-1; //up
    dir[1][1].first=0; dir[1][1].second=1; //down
    while(t--){
        scanf("%d%d",&m,&n);
        check=0; k=0; flag=0;
        initialize();
        //printf("m=%d n=%d\n",m,n);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                scanf("\n%c",&maze[i][j]);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if((i==0 || j==0 || j==n-1 || i==m-1) && maze[i][j]=='.'){
                    check++;
                    if(check<=2){
                        a[k].first=i; a[k].second=j;
              //          printf("a=%d b=%d k=%d\n",a[k].first,a[k].second,k);
                        k++;
                    }
                    else if(check>2){
                            flag=1;
                            break;
                    }
                //    printf("check=%d\n",check);
                }
            }
            if(flag==1)
                break;
        }
        //printf("check final=%d\n",check);
        if((bfs(a[0].first,a[0].second)) && check==2){
            printf("valid\n");
            continue;
        }
        else{
            printf("invalid\n");
            continue;
        }
    }
    return 0;
}
/*
6
4 4
####
#...
#.##
#.##
5 5
#.###
#..##
##..#
#.#.#
###.#
1 1
.
5 1
#
#
.
.
#
2 2
#.
.#
3 4
#..#
#.##
#.##
*/

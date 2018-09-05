#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
bool primes[11000];
int limit=11000;
void sieve_of_eratosthene(){
    memset(primes,true,sizeof(primes));
    for(int p=2;p*p<=limit;p++){
        if(primes[p]==true){
            for(int i=p*2;i<=limit;i+=p)
                primes[i]=false;
        }
    }
}
int bfs(int p1, int p2){
    bool explored[limit];
    int dist[limit];
    for(int i=1000;i<limit;i++){
        explored[i]=false;
        dist[i]=999999;
    }
    dist[p1]=0;
    queue<int> que;
    que.push(p1);
    explored[p1]=true;
    int num,l,n,q,f1,f2,f3;
    while(que.size()!=0 && explored[p2]==false){
        num=que.front();
        //cout<<"num = "<<num<<endl;
        que.pop();
        f1=0; f2=0; f3=0;
        for(int i=0;i<4;i++){
            if(i<3){
            n=num;
            l=num/pow(10,i);
            l=l%10;
            n=n-l*pow(10,i);
            q=n;
            //cout<<n<<endl;
            for(int j=0;j<=9 && i<3;j++){
                n=n+j*pow(10,i);
                if(primes[n]==true && explored[n]==false && n<10000){
                    dist[n]=dist[num]+1;
                    //cout<<"i = "<<i<<" j = "<<j<<" n = "<<n<<" dist["<<n<<"] = "<<dist[n]<<" dist["<<num<<"] = "<<dist[num]<<endl;
                    explored[n]=true;
                    if(explored[p2]==true){
                        f1=1;
                        break;
                    }
                    que.push(n);
                }
                n=q;
            }
            }
            if(i==3){
            n=num;
            l=num/1000;
            n=n-l*1000;
            q=n;
            //cout<<n<<endl;
            for(int j=1;j<=9 && i==3;j++){
                n=n+j*pow(10,i);
                if(primes[n]==true && explored[n]==false && n<10000){
                    dist[n]=dist[num]+1;
                    //cout<<"i = "<<i<<" j = "<<j<<" n = "<<n<<" dist["<<n<<"] = "<<dist[n]<<" dist["<<num<<"] = "<<dist[num]<<endl;
                    explored[n]=true;
                    if(explored[p2]==true){
                        f1=1;
                        break;
                    }
                    que.push(n);
                }
                n=q;
            }
            }
            if(f1==1){
                f2=1;
                break;
            }
        }
        if(f2==1)
            break;
    }
    return dist[p2];
}
int main(void)
{
    int t;
    scanf("%d",&t);
    sieve_of_eratosthene();
    while(t--){
        int p1,p2;
        scanf("%d %d",&p1,&p2);
        int cost=bfs(p1,p2);
        cout<<cost<<endl;
    }
    return 0;
}

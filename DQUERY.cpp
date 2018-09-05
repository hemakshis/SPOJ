#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int N=30010;
const int Q=200010;
const int Num=1e6+7;
const int B=175;
int a[N];

struct query
{
    int i,l,r;
} q[Q];

int ans[Q],answer=0,cnt[Num];

bool comp(query a,query b){
    if(a.l/B != b.l/B){
        return a.l/B < b.l/B;
    }
    return a.r<b.r;
}

void add(int pos){
    //cout<<"Incremented "<<a[pos]<<endl;
    cnt[a[pos]]++;
    if(cnt[a[pos]]==1)
        answer++;
}

void rem(int pos){
    //cout<<"Decremented "<<a[pos]<<endl;
    cnt[a[pos]]--;
    if(cnt[a[pos]]==0)
        answer--;
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    long m;
    int l,r,t;
    scanf("%ld",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&l,&r);
        l--;    r--;
        q[i].i=i;
        q[i].l=l;   q[i].r=r;
    }
    sort(q,q+m,comp);
    int L,R,currL=0,currR=-1;
    for(int i=0;i<m;i++){
        L=q[i].l;   R=q[i].r;
        //cout<<"Required L = "<<L<<" Required R = "<<R<<endl;

        while(currR<R)
        {
            currR++;
            add(currR);
        }

        while(currR>R)
        {
            rem(currR);
            currR--;
        }

        while(currL<L)
        {
            rem(currL);
            currL++;
        }

        while(currL>L)
        {
            currL--;
            add(currL);
        }

        //cout<<"currL = "<<currL<<" currR = "<<currR<<endl;

        ans[q[i].i]=answer;
    }

    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);

    return 0;
}

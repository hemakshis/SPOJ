#include <bits/stdc++.h>
#define LL long long
#define scn(a) scanf("%lld",&a)
#define pb push_back
#define INF 1000000007
using namespace std;
LL store[1000000]={NULL};
LL n,m;
LL cal(LL mid)
{
    LL sum=0;
    for(LL i=0;i<n;i++)
        if(store[i]>=mid)sum+=store[i]-mid;
    return sum;
}
int main()
{
    //LL n,m;
    scn(n);scn(m);

    LL mmin=INF,mmax=0;
    for(LL i=0;i<n;i++)
    {

        scn(store[i]);
        if(store[i]>mmax)mmax=store[i];
        if(store[i]<mmin)mmin=store[i];
    }
    sort(store,store+n);
    LL mid;
    LL ans=0;
mmin=0;
    //cout<<"???"<<endl;
    while(mmin<=mmax)
    {
        //cout<<"mmin "<<mmin<<endl;
        //cout<<"mmax "<<mmax<<endl;
        mid=(mmin+mmax)/2;
        if(mid==mmin)break;
        //cout<<"mid "<<mid<<endl;
        LL tmp=cal(mid);
        if(tmp>=m){if(mid>ans)ans=mid;mmin=mid;}
        if(tmp<m)mmax=mid;
    }
    printf("%lld",ans);
}

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 1000009
#define MAX_SIZE 100000
typedef long long ll;
using namespace std;
ll a,v,b,ans,cnt,times;
bool is_prime[MAX];
vector<ll> divisors[MAX];
ll divs(ll a, ll b) { return (a+b-1)/b; }
void sieve(){
    //cout<<"in sieve"<<endl;
    for(ll i=2;i<MAX;i++)
        is_prime[i]=true;
    for(ll i=2;i<MAX;i++){
        if(is_prime[i]==true){
            //cout<<"aho"<<endl;
            for(ll j=i*2;j<MAX;j+=i)
                is_prime[j]=false;
            for(ll x=divs(a,i)*i;x<=b;x+=i)
                divisors[x-a].push_back(i);
        }
    }
    //cout<<"out of sieve"<<endl;
}
int main(void)
{
    int n;
    scanf("%lld%lld%d",&a,&b,&n);
    sieve();
    ans=0;
    vector<ll> :: iterator iv;
    for(ll i=a;i<=b;i++){
        times=1;
        v=i;
        //cout<<"i = "<<i<<" i-a = "<<i-a<<endl;
        for(iv=divisors[i-a].begin();iv!=divisors[i-a].end();iv++){
            cnt=0;
            while(v%(*iv)==0){
                cnt++;
                v/=(*iv);
            }
            if(cnt!=0)
                times*=(1+cnt);
        }
        if(v>1)
            times*=2;
    if(times==n)
            ans++;
    }
    printf("%lld\n",ans);
    return 0;
}

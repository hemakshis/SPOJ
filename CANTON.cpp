#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX 10000000
using namespace std;
vector<long long> v;
vector<long long> :: iterator iv;
int main(void)
{
    int t;
    long n;
    scanf("%d",&t);
    for(long i=1;i<=MAX;i++){
        if(i==1)
            v.push_back(1);
        else
            v.push_back(i+v[i-1]);
    }
    while(t--){
        scanf("%ld",&n);
        iv=lower_bound(v.begin(),v.end(),n);
        long idx=iv-v.begin()+1;

    }
    return 0;
}

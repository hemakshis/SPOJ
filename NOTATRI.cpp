#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int bst(int n,long int arr[],long int x){
    int st=0,en=n-1;
    int mid;
    while(st<=en){
        mid=(st+en)/2;
        if(arr[mid]<=x){
            st=mid+1;
        }
        else{
            en=mid-1;
        }
    }
    return mid;
}

int main(void)
{
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0)
            break;
        vector<long int> arr;
        vector<long int> :: iterator idx;
        long int x,ans=0;
        for(int i=0;i<n;i++){
            scanf("%ld",&x);
            arr.push_back(x);
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                x=arr[i]+arr[j];
                //cout<<"x="<<x<<endl;
                idx=upper_bound(arr.begin(),arr.end(),x);
                if(idx!=arr.end()){
                    ans+=n-(idx-arr.begin());
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

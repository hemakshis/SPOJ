#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long ll;
long long int Merge_and_CountSplitInv(long int A[], int p, int q, int r)
{
    int i,j,k;
    int n1=q-p;
    int n2=r-q+1;
    int L[n1], M[n2];
    int D[n1+n2];
    for(i=0;i<n1;i++){
        L[i]=A[p+i];
    }
    for(j=0;j<n2;j++){
        M[j]=A[q+j];
    }
    i=0;
    j=0;
    long long int n=0;
    k=0;
    while(i<n1 && j<n2){
        if(L[i]<=M[j] && i<n1 && j<n2){
            D[k++]=L[i++];
        }
        else{
            n=n+(n1-i);
            D[k++]=M[j++];
        }
    }
    while(i<n1){
        D[k++]=L[i++];
    }
    while(j<n2){
        D[k++]=M[j++];
    }
    for(i=p;i<=r;i++){
        A[i]=D[i-p];
    }
    return n;
}
long long int Merge_and_Count(long int A[], int p, int r)
{
    long long int n=0;
    if(p<r)
    {
        int q=(p+r)/2;
        n=Merge_and_Count(A,p,q);
        n+=Merge_and_Count(A,q+1,r);
        n+=Merge_and_CountSplitInv(A,p,q+1,r);
    }
    return n;
}

ll getSum(ll* BIT,ll idx){
    ll sum=0;
    while(idx>0){
        sum+=BIT[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

void update(ll* BIT,long maxVal,long val,long idx){
    while(idx<=maxVal){
        BIT[idx]+=val;
        idx+=(idx & -idx);
    }
}

ll getInversions(int n,long* A,long maxVal){
    ll* BIT = (ll*)malloc((maxVal+1)*sizeof(ll));
    for(long i=0;i<=maxVal;i++)
        BIT[i]=0;
    ll inversions=0;
    for(long i=1;i<=n;i++){
        if(A[i]>0){
            inversions+=(getSum(BIT,A[i]-1));
            update(BIT,maxVal,A[i],A[i]);
        }
    }
    return inversions;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        long A[n+5],i,maxVal=-1;
        for(i=1;i<=n;i++){
            scanf("%ld",&A[i]);
            maxVal=max(maxVal,A[i]);
        }
        //cout<<"maxVal = "<<maxVal<<endl;
        printf("%lld\n",getInversions(n,A,maxVal));
    }
    return 0;
}

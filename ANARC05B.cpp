#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#define MAX 10009
using namespace std;

int main(void)
{
    while(1){
        vector<int> v1,v2;
        int sum1[MAX],sum2[MAX];
        for(int d=0;d<MAX;d++){
            sum1[d]=0;
            sum2[d]=0;
        }
        int n1,n2,i,x,j,k,l;
        scanf("%d",&n1);
        if(n1==0)
            break;
        i=0; j=0;
        for(i=0;i<n1;i++){
            scanf("%d",&x);
            v1.push_back(x);
        }
        scanf("%d",&n2);
        for(j=0;j<n2;j++){
            scanf("%d",&x);
            v2.push_back(x);
        }
        long int maxSum=0;
        k=0;
        for(i=0;i<n1;i++){
            if(binary_search(v2.begin(),v2.end(),v1[i])==false)
                sum1[k]+=v1[i];
            else{
                k++;
                maxSum+=v1[i];
            }
        }
        /*
        for(i=0;i<=k;i++)
            cout<<sum1[i]<<" ";
        cout<<endl;
        */
        l=0;
        for(j=0;j<n2;j++){
            if(binary_search(v1.begin(),v1.end(),v2[j])==false)
                sum2[l]+=v2[j];
            else
                l++;
        }
        /*
        for(j=0;j<=l;j++)
            cout<<sum2[j]<<" ";
        cout<<endl;
        */
        i=0; j=0;
        while(i<=k && j<=l){
            if(sum1[i]>sum2[j]){
                maxSum+=sum1[i];
            }
            else{
                maxSum+=sum2[j];
            }
            i++; j++;
        }
        printf("%ld\n",maxSum);
    }
    return 0;
}
/*
13 3 5 7 9 20 25 30 40 55 56 57 60 62
11 1 4 7 11 14 25 44 47 55 57 100
4 -5 100 1000 1005
3 -12 1000 1001
0
*/

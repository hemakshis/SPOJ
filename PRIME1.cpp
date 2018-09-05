#include <stdio.h>
#include <cmath>
#include <vector>
#include <iostream>
//#include <cassert>
#include <string.h>
using namespace std;
#include <iostream>
#include <stdio.h>
using namespace std;
bool is_prime(int n){
	if(n==1) return false;
	if(n<4 && n>1) return true;
	if(n%2==0) return false;
	for(int i=3;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		long int m,n;
		scanf("%ld%ld",&m,&n);
		for(long int i=m;i<=n;i++){
			if(is_prime(i))
				printf("%ld\n",i);
			else printf("");
		}
	}
	// your code here

	return 0;
}
/*
long int n,m,i,j,k,l,p;
void simple_sieve(long int limit,vector<long int>& prime){
    bool mark[limit+1];
    memset(mark,true,sizeof(mark));
    for(p=2;p*p<limit;p++){
        if(mark[p]==true){
            for(i=p*2;i<limit;i+=p){
                mark[i]=false;
      //          cout<<"marked false "<<i<<endl;
            }
        }
    }
    if(n==1) n=2;
    for(j=2;j<limit;j++){
        if(mark[j]==true){
            prime.push_back(j);
        }
    }
    for(j=n;j<limit;j++){
        if(mark[j]==true)
            printf("%ld\n",j);
    }
}
void segmented_sieve(){
    long int limit=floor(sqrt(m))+1;
    //cout<<"n = "<<n<<" m = "<<m<<" limit = "<<limit<<endl;
    vector<long int> prime;
    simple_sieve(limit,prime);
    /*for(long int i=n;i<limit;i++){
        if(mark[i]==true)
            printf("%ld\n",i);
    }
    //cout<<"simple sieve over"<<endl;
    long int low=limit;
    long int lowlim;
    long int high=2*limit;
    if(high>=m)
        high=m;
    bool mark[limit+1];
    while(low<m){
        memset(mark,true,sizeof(mark));
        for(i=0;i<prime.size();i++){
            lowlim=floor(low/prime[i])*prime[i];
            //printf(" low = %ld high = %ld lowlimm = %ld",low,high,lowlim);
            if(lowlim<low)
                lowlim+=prime[i];
            for(j=lowlim;j<=high;j+=prime[i]){
                mark[j-low]=false;
               // cout<<"marked "<<j<<" as false"<<endl;
            }
        }
        for(i=low;i<=high;i++){
            if(i>=n){
            if(mark[i-low]==true)
                printf("%ld\n",i);
            }
        }
        low=low+limit;
        high=low+limit;
        if(high>=m)
            high=m;
    }
}
int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        //long int n,m;
        scanf("%ld%ld",&n,&m);
        segmented_sieve();
        printf("\n");
    }
    return 0;
}
*/

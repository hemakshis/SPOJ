#include <iostream>
using namespace std;

int main() {
	while(1){
		int n;
		m:
		cin>>n;
		if(n==-1)
			break;
		else{
			int sum=0,x[n],ans=0;
			for(int i=0;i<n;i++){
				cin>>x[i];
				sum+=x[i];
			}
			int q=sum/n;
			if(sum%n!=0){
				cout<<"-1"<<endl;
				goto m;
			}
			for(int i=0;i<n;i++){
				if(x[i]<q){
					ans=ans+q-x[i];
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;
int a;
long long int b,x,y;
int modulo(){
	x=1,y=a;
	while(b>0){
		if(b%2==1)
			x=(x*y)%10;
		y=(y*y)%10;
		b/=2;
	}
	return x%10;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %lld",&a,&b);
		printf("%d\n",modulo());
	}
	// your code here

	return 0;
}

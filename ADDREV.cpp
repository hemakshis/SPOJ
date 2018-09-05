#include <iostream>
#include <math.h>
using namespace std;
int _reverse(int x){
    int r,y=0;
    while(x){
        r=x%10;
        y=y*10+r;
        x/=10;
    }
    return y;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        cout<<_reverse(_reverse(a)+_reverse(b))<<endl;
    }
    return 0;
}

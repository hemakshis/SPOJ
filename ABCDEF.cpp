#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main(void)
{
    int n,w;
    scanf("%d",&n);
    vector<int> vec;
    for(int i=0;i<n;i++){
        scanf("%d",&w);
        vec.push_back(w);
    }
    long int x,y,z1,z2,ans=0;
    vector<long int> lhs;
    vector<long int> rhs;
    vector<int> :: iterator iv1;
    vector<int> :: iterator iv2;
    vector<int> :: iterator iv3;
    for(iv1=vec.begin();iv1!=vec.end();iv1++){ //a
        for(iv2=vec.begin();iv2!=vec.end();iv2++){ //b
            x=((*iv1) * (*iv2));
            for(iv3=vec.begin();iv3!=vec.end();iv3++){ //c
                lhs.push_back(x+(*iv3));
            }
        }
    }
    for(iv1=vec.begin();iv1!=vec.end();iv1++){ //d
        if((*iv1)!=0){
            for(iv2=vec.begin();iv2!=vec.end();iv2++){ //e
                for(iv3=vec.begin();iv3!=vec.end();iv3++){ //f
                    if( ( (*iv2)+(*iv3) )!=0 ){
                        x=(*iv2) + (*iv3);
                        y=x * (*iv1);
                        rhs.push_back(y);
                    }
                    else
                        rhs.push_back(0);
                }
            }
        }
    }
    int q;
    sort(rhs.begin(),rhs.end());
    sort(lhs.begin(),lhs.end());
    vector<long int> :: iterator it;
    vector<long int> :: iterator ia;
    vector<long int> :: iterator ib;
    for(it=lhs.begin();it!=lhs.end();){
        ib=upper_bound(lhs.begin(),lhs.end(),(*it))-1;
        y=(ib-lhs.begin())-(it-lhs.begin())+1;
        q=binary_search(rhs.begin(),rhs.end(),(*it));
        if(q){
            ia=lower_bound(rhs.begin(),rhs.end(),(*it));
            z1=ia-rhs.begin();
            ia=upper_bound(rhs.begin(),rhs.end(),(*it))-1;
            z2=ia-rhs.begin();
            ans+=y*(z2-z1+1);
        }
        it=ib+1;
    }
    printf("%ld\n",ans);
    return 0;
}

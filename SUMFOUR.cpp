#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
int main(void)
{
    int n;
    scanf("%d",&n);
    vector<unsigned long int> lists[4];
    unsigned long int a,b,c,d;
    while(n--){
        scanf("%lu%lu%lu%lu",&a,&b,&c,&d);
        lists[0].push_back(a);
        lists[1].push_back(b);
        lists[2].push_back(c);
        lists[3].push_back(d);
    }
    for(int i=0;i<4;i++)
        sort(lists[i].begin(),lists[i].end());
    vector<unsigned long int> a_b;
    vector<unsigned long int> c_d;
    vector<unsigned long int> :: iterator i;
    vector<unsigned long int> :: iterator j;
    for(i=lists[0].begin();i!=lists[0].end();i++){
        for(j=lists[1].begin();j!=lists[1].end();j++){
            a_b.push_back(*i + *j);
        }
    }
    for(i=lists[2].begin();i!=lists[2].end();i++){
        for(j=lists[3].begin();j!=lists[3].end();j++){
            c_d.push_back(*i + *j);
        }
    }
    sort(a_b.begin(),a_b.end());
    sort(c_d.begin(),c_d.end());
    unsigned long int x=0;
    unsigned long int ans=0;
    pair<vector<unsigned long int> :: iterator,vector<unsigned long int> :: iterator> bounds;
    for(i=a_b.begin();i!=a_b.end();i++){
        x=-(*i);
        if(binary_search(c_d.begin(),c_d.end(),x)){
            bounds=equal_range(c_d.begin(),c_d.end(),x);
            ans+=bounds.second-bounds.first;
        }
    }
    printf("%lu\n",ans);
    return 0;
}

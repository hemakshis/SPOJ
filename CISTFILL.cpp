#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <limits>
#include <utility>
#define MAX 50009
#define EPSILON 0.000000001
using namespace std;
vector<double> base;
vector<double> dim[MAX];
double n,b,h,w,d;
double INF=3000000000;
double v,volCist;
void initialize(){
    base.clear();
    for(int i=0;i<n;i++)
        dim[i].clear();
}

bool myComp(double i,double j) { return abs(i-j) < EPSILON; }


double calVol(double m){
    double vol=0;
    for(int i=0;i<n;i++){
        if(dim[i][0]<m){
            if(dim[i][0]+dim[i][1]<=m){
                vol+=dim[i][1]*dim[i][2]*dim[i][3];
            }
            else{
                vol+=(m-dim[i][0])*dim[i][2]*dim[i][3];
            }
        }
    }
    return vol;
}

double bst(){
    double st=double(base[0]),en=double(base[n-1]);
    double mid;
    double tmp=0;
    double ans=double(INF);
    while(st<en){

        if(myComp(st,en))
            break;
        mid=(st+en)/2;
        //cout<<"st = "<<st<<" en = "<<en<<" mid = "<<mid<<endl;
        tmp=calVol(mid);
        //cout<<"tmp = "<<tmp<<endl;
        if(tmp<v){
            st=mid;
        }
        else{
            if(ans>mid)
                ans=mid;
            en=mid;
        }
    }
    return ans;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lf",&n);
        volCist=0;
        initialize();
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&b,&h,&w,&d);
            base.push_back(b+h);
            dim[i].push_back(b);
            dim[i].push_back(h);
            dim[i].push_back(w);
            dim[i].push_back(d);
            //cout<<dim[i][0]<<" "<<dim[i][1]<<" "<<dim[i][2]<<" "<<dim[i][3]<<endl;
            volCist+=h*w*d;
        }
        sort(base.begin(),base.end());
        scanf("%lf",&v);
        if(v>volCist){
            printf("OVERFLOW\n");
            continue;
        }
        printf("%.2f\n",bst());
    }
    return 0;
}

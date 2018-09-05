#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
bool check(string& str){
    stack<char> s;
    long ans=0,close=0,open=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='{'){
            s.push(str[i]);
            close++;
        }
        else{
            if(s.empty()){
                open++;
            }
            else{
                close--;
            }
        }
    }
    return s.empty();
}
int main(void)
{
    while(1){
        string str;
        cin>>str;
        if(str[0]=='-')
            break;
        long changes=0;
    }
    return 0;
}

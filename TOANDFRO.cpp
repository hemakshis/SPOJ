#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0)
            return 0;
        char str[205], matrix[205][25];
        scanf("%s",&str);
        int row=strlen(str)/n;
        int column=n,k=0,i,j;
        for(i=0;i<row;i++){
            if(i%2==0){
                for(j=0;j<column;j++){
                    matrix[i][j]=str[k];
                    k++;
                    if(k==strlen(str))
                        break;
                }
            }
            else{
                for(j=column-1;j>=0;j--){
                    matrix[i][j]=str[k];
                    k++;
                    if(k==strlen(str))
                        break;
                }
            }
        }
        for(j=0;j<column;j++)
            for(i=0;i<row;i++)
                printf("%c",matrix[i][j]);
        printf("\n");
    }
    return 0;
}
/*
5
toioynnkpheleaigshareconhtomesnlewx
3
ttyohhieneesiaabss
*/

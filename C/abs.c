#include<stdio.h>

int main(){
    int bits = sizeof(int)*8-1;
    while(1){
    int n = 0;
    scanf("%d",&n);
    int i = (n^(n>>bits))-(n>>bits);
    printf("%d\n",i);
    }
    return 0;
}
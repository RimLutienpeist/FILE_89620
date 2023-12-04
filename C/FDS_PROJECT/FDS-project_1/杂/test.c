#include<stdio.h>

double POWER(long long int n,double x);

int main() {
    long long int N = 0;
    double x = 0,res = 0;

    scanf("%d %lf",&N,&x);
    res = POWER(N,x);
    printf("%lf\n",res);

    return 0;
}

double POWER(long long int n,double x){
    double res = 1;
    
    while (n > 0) {
        if (n % 2 == 1) {
            res *= x;
        };
        x *= x;
        n /= 2;
    };
    
    return res;
}
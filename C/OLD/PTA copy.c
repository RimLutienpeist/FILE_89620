#include <stdio.h>

int IsOdd(int number);
int IsEven(int number);

double Power(double x, int n);

int main()
{
    double x;
    int n;
    scanf("%lg%d", &x, &n);
    printf("%.8g\n", Power(x, n));
    return 0;
}

/* 你提交的代码将被嵌在这里 */
double Power(double x, int n){
    if(x == 0){
        if(n<=0){
            printf("不正确的参数!\n");
            return 0;
        }else if(n>0){
            return 0;
        };
    }else{
        if(n%2 == 0){
            return Power(x,n/2) * Power(x,n/2);
        }else{
            return x * Power(x,(n-1)/2) * Power(x,(n-1)/2);
        };
    };
}
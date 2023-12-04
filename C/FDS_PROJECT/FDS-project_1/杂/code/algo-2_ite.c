#include<stdio.h>
#include<time.h>
clock_t start,stop;  
double duration;  //define the variate recording the time consumed for each round of calculation 
#define K 1000000;  //definethe number of times this function is called
#define X 1.0001;   //define the base number as 1.0001 for the calculation

double POWER(long long int n,double x);

int main() {
    printf("Please enter exponent:\n");
    long long int N = 0,i = 0;  //N is the variable that stores the exponent 
    double ttime = 0,ticks = 0,x = 0,res = 0;   //ttime is the total time,   ticks is the total ticks,    x is the variable that stores the base number
    long long T = K1;    //T is the variable that stores the number of times this function is called

    scanf("%lld",&N); //input the exponent
    x = X;  //set the base number as 1.0001

    for(i = 0;i<T;i++){ //repeat the calculation for K times
        start = clock();    //start time

        // Call iterative function
        res = POWER(N,x);
        // printf("%lf\n",res);

        stop = clock(); //stop time
        duration = ((double)(stop-start))/CLK_TCK;  //calculate the time duration of each round of calculation 
        ticks += stop - start;  //The total time is calculated by adding up the time spent in each round
        ttime += duration;  //The total time is calculated by adding up the time spent in each round

    };

    printf("T = %lld\nticks = %lf\ntotal time = %lf\n",T,ticks,ttime);    //output K,ticks and total time
    return 0;
}

double POWER(long long int n,double x){
    double res = 1;
    
    while (n > 0) {

        //determine the parity of N
        if (n % 2 == 1) {
            res *= x;
        };

        //To multiply the next result by x^2, while reducing n/2 operations to achieve iteration
        x *= x;
        n /= 2;
    };
    
    return res;
}
#include<stdio.h>
#include<time.h>
clock_t start,stop;  
double duration;  //define the variate recording the time consumed for each round of calculation 
#define K 1000;  //definethe number of times this function is called
#define X 1.0001;   //define the base number as 1.0001 for the calculation

double EVEN(long long int n,double x);
double ODD(long long int n,double x);

int main(){
    // printf("Please enter integer and base-number in turn:\n");
    printf("Please enter exponent:\n");

    long long int N = 0,i = 0;  //N is the variable that stores the exponent 
    double ttime = 0,ticks = 0,x = 0,res = 0;   //ttime is the total time,   ticks is the total ticks,    x is the variable that stores the base number
    long long T = K1;    //T is the variable that stores the number of times this function is called

    scanf("%lld",&N); //input the exponent
    x = X;  //set the base number as 1.0001

    for(i = 0;i<T;i++){ //repeat the calculation for K times
        start = clock();    //start time

        //determine the parity of N and call the corresponding recursive function
        if(N%2){
            res = ODD(N,x);
            // printf("%lf\n",res);
        }else{
            res = EVEN(N,x);
            // printf("%lf\n",res);
        };

        stop = clock(); //stop time
        duration = ((double)(stop-start))/CLK_TCK;  //calculate the time duration of each round of calculation 
        ticks += stop - start;  //The total time is calculated by adding up the time spent in each round
        ttime += duration;  //The total time is calculated by adding up the time spent in each round
    };

    printf("T = %lld\nticks = %lf\ntotal time = %lf\n",T,ticks,ttime);    //output K,ticks and total time
    return 0;
}

//if N is odd,then this function will be called for
double ODD(long long int n,double x){
    //if exponent <= 1,then it return x to avoid resulting errors
    if(n<=1){
        return x;
    };

    n = (n-1)/2;
    return EVEN(n,x) * EVEN(n,x) * x;
}

//if N is even,then this function will be called for
double EVEN(long long int n,double x){
    //if exponent <= 1,then it return x to avoid resulting errors
    if(n<=1){
        return x;
    };

    n = n/2;
    return EVEN(n,x) * EVEN(n,x);    
}

#include<stdio.h>
#include<time.h>
clock_t start,stop;  
double duration;  //define the variate recording the time consumed for each round of calculation 
#define K1 1000;  //definethe number of times this function is called
#define X 1.0001;   //define the base number as 1.0001 for the calculation

int main(){
    printf("Please enter exponent:\n");
    long long int N = 0,i = 0;  //N is the variable that stores the exponent 
    double ttime = 0,ticks = 0,x = 0;   //ttime is the total time,   ticks is the total ticks,    x is the variable that stores the base number
    long long T = K1;    //T is the variable that stores the number of times this function is called

    scanf("%lld",&N); //input the exponent
    x = X;  //set the base number as 1.0001


    for(i = 0;i<T;i++){ //repeat the calculation for K times
        
        start = clock();    //start time
        long long int res = x;
        
        //use N−1 multiplications to get the result
        for(int i = 1;i<N;i++){
            res *= x;
        };

        stop = clock(); //stop time
        duration = ((double)(stop-start))/CLK_TCK;  //calculate the time duration of each round of calculation 
        ticks += stop - start;  //The total ticks is calculated by adding up the ticks spent in each round
        ttime += duration;  //The total time is calculated by adding up the time spent in each round
    };

    printf("T = %lld\nticks = %lf\ntotal time = %lf\n",T,ticks,ttime);    //output K,ticks and total time
    return 0;
}
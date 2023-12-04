#include<stdio.h>
#include<time.h>
// #include<setjmp.h>

clock_t start,stop;  
double duration;  //the time consumed for each round of calculation 
#define K1 1000;  //times the multi function is called
#define K2 1000;  //times the recursion is called
#define K3 1000000;  //times the iteration function is called
#define X 1.0001;   //define the base number as 1.0001
// jmp_buf jmpbuffer;


void multi();
void recursion();
void iteration();
double EVEN(long long int n,double x);
double ODD(long long int n,double x);
double POWER(long long int n,double x);


int main(){
    // setjmp(jmpbuffer);  //to restart the program after finishing one algorithm
    
    int q = 0;
    printf("\n\nPlease choose the algorithm you want run:\n"
            "1.multiplication\n2.recursion\n3.iteration\nPlease input '1', '2' or '3'.\n");
mainReInput:
    scanf("%d",&q);

    if(q == 1){ //run different algorithm
        multi(); 
    }else if(q == 2){
        recursion();
    }else if(q == 3){
        iteration();
    }else{
        printf("Error,please input again.\n");
        goto mainReInput; //choose algorithm again
    }

    return 0;
}




//multiplication
void multi(){
    long long int N = 0,i = 0;  //N is exponent 
    double ttime = 0,ticks = 0,x = 0;   //ttime is the total time, ticks is the total ticks, x is the base number
    long long T = K1;    //T is the number of times this function will be called
    printf("Now the K is set to %lld\n",T);
    printf("Please enter exponent:\n");

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

    // longjmp(jmpbuffer,1);
}




void recursion(){
    long long int N = 0,i = 0;  //N is exponent 
    double ttime = 0,ticks = 0,x = 0,res = 0;   //ttime is the total time, ticks is the total ticks, x is the base number
    long long T = K2;    //T is the number of times this function will be called
    printf("Now the K is set to %lld\n",T);
    printf("Please enter exponent:\n");

    scanf("%lld",&N); //input the exponent
    x = X;  //set the base number as 1.0001

    for(i = 0;i<T;i++){ //repeat the calculation for K times
        start = clock();

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
        ticks += stop - start;  
        ttime += duration;  
    };

    printf("T = %lld\nticks = %lf\ntotal time = %lf\n",T,ticks,ttime);    //output K,ticks and total time
    // longjmp(jmpbuffer,1);
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




void iteration() {
    long long int N = 0,i = 0;  //N is the variable that stores the exponent 
    double ttime = 0,ticks = 0,x = 0,res = 0;   //ttime is the total time,   ticks is the total ticks,    x is the variable that stores the base number
    long long T = K3;    //T is the number of times this function is called
    printf("Now the K is set to %lld\n",T);
    printf("Please enter exponent:\n");

    scanf("%lld",&N); //input the exponent
    x = X;  //set the base number as 1.0001

    for(i = 0;i<T;i++){ //repeat the calculation for K times
        start = clock();    //start time

        // Call iterative function
        res = POWER(N,x);
        // printf("%lf\n",res);

        stop = clock(); //stop time
        duration = ((double)(stop-start))/CLK_TCK;   
        ticks += stop - start;  
        ttime += duration;  

    };

    printf("T = %lld\nticks = %lf\ntotal time = %lf\n",T,ticks,ttime);    //output K,ticks and total time
    // longjmp(jmpbuffer,1);
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
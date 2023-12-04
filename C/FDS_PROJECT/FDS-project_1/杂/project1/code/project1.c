#include<stdio.h>
#include<time.h>
#include<math.h>

// three loop numbers for each function
#define K1 100000 // for function1 Multiples
#define K2 100000000 // for function2 Iteration
#define K3 100000000 // for function3 Recursion
#define dE 0.000001 // the threshold of error

// clock time record
clock_t start, stop, Ticks[3][8];

// three functions to calculate the X^N
double Multiples(double X, int N);
double Iteration(double X, int N);
double Recursion(double X, int N);

int main(){
    double X = 1.0001; // the base of X
    int N[8] = {1000, 5000, 10000, 20000, 40000, 60000, 80000, 100000}; // the power of X   
    int i, j; // loop variables
    // calculate the time for each function
    for(i = 0; i < 8; i++){
        start = clock(); // start time
        for(j = 0; j < K1; j++) Multiples(X, N[i]);
        stop = clock(); // stop time
        if(abs(Multiples(X, N[i]) - pow(X, N[i])) > dE) printf("Error!\n"); // check the result is correct or not
        Ticks[0][i] = stop - start; // calculate the time ticks
    }  
    for(i = 0; i < 8; i++){ // do the same for Iteration and Recursion
        start = clock();
        for(j = 0; j < K2; j++) Iteration(X, N[i]);
        stop = clock();
        if(abs(Iteration(X, N[i]) - pow(X, N[i])) > dE) printf("Error!\n");
        Ticks[1][i] = stop - start;
    }
    for(i = 0; i < 8; i++){ // do the same for Iteration and Recursion
        start = clock();
        for(j = 0; j < K3; j++) Recursion(X, N[i]);
        stop = clock();
        if(abs(Recursion(X, N[i]) - pow(X, N[i])) > dE) printf("Error!\n");
        Ticks[2][i] = stop - start;
    }

    // print the result
    printf("Ticks per second = %d\n", CLOCKS_PER_SEC); // print the clock ticks per second
    printf("K1 = %d, K2 = %d, K3 = %d\n", K1, K2, K3); // print the loop numbers
    printf("     N Ticks1 Ticks2 Ticks3\n"); // print the table head
    for(i = 0; i < 8; i++){
        printf("%6d %6ld %6ld %6ld\n", N[i], Ticks[0][i], Ticks[1][i], Ticks[2][i]); // print the table
    }
    return 0;
}

//function1 multiplications
double Multiples(double X, int N){
    int i;
    double result = 1;
    for(i = 0; i < N; i++){
        result *= X;    // X^N = X * X * X * ... * X
    }
    return result;
}

//function2 iteration
double Iteration(double X, int N){
    double result = 1; 
    while(N > 0){
        if(N % 2 == 1){
            result *= X; //if N is odd, X^N = X * X^(N-1)
        }
        X *= X;     // X^N = X^(N/2) * X^(N/2)
        N /= 2;
    }
    return result;
}

//funtion3 recursion
double Recursion(double X, int N){
    if(N == 0) return 1; // X^0 = 1 (N >= 0
    if(N == 1) return X; // recusion out condition
    else if(N % 2) return Recursion(X * X, N / 2) * X; //if N is odd, X^N = X * X^(N-1)
    else return Recursion(X * X, N / 2); // X^N = X^(N/2) * X^(N/2)
}
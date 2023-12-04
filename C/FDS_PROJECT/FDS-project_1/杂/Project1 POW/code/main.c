#include <stdio.h>
#include <time.h>

clock_t start,stop; //clock_t is a built-in type for processor time (ticks)
clock_t begin,end; //clock_t is a built-in type for processor time (ticks)
double duration,que[9]; /*records the run time (seconds) of a function and que is Used 
to store Total Time for each N */

double pow1(double X,int N)
{
    double res=1;
    while(N--) res*=X;//use for-loop to multiply X repetitively
    return res;
}
double pow2_ite(double X,int N)
{
    double result = 1;
    while (N > 0){
    	if (N % 2 == 1) result = result * X; /*multiply extra x when n is odd; store calculation 
		to result when n = 1*/
	    X = X * X;
        N = N / 2; //get prepared of x^(n/2) * x^(n/2) when n is even
    }
    return result;
}
double pow2_rec(double X,int N) 
{
    if (N == 0) return 1;
    if (N == 1) return X;
    if (N % 2 == 0) return pow2_rec(X * X, N / 2); // return the result when n is even
    else return pow2_rec(X * X, N / 2) * X; // multiply extra x when n is odd
}

int main(){
    double X=1.0001; //set test base number
    int N[8]={1e3,5e3,1e4,2e4,4e4,6e4,8e4,1e5}; //set an array to store N
    printf("exponent                        ");
    for(int i=0;i<8;i++) printf("%16d",N[i]);
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t  \n");
    //printf("\t��������");
    printf("\nAlgorithm1                      ");
    for(int i=0;i<8;i++)  printf("%16lf",pow1(X,N[i])); //output result
    printf("\nAlgorithm2(interative version)  ");
    for(int i=0;i<8;i++)  printf("%16lf",pow2_ite(X,N[i])); //output result
	printf("\nAlgorithm2(recursive version)   ");
    for(int i=0;i<8;i++)  printf("%16lf",pow2_rec(X,N[i])); //output result
    
    int K=1e4;//K stands for the number of times this function runs repeatedly 
    printf("\n\t\t\t\t\t\t\t\t\tAlgorithm1  ");
    printf("\nK:                              ");
    for(int i=0;i<8;i++) printf("%16d",K);
    printf("\nDuration(e-4):                  ");
    for(int i=0;i<8;i++){
    	K=1e4;
    	begin=clock(); //records the ticks at the beginning of the function call
    	start = clock(); 
		while(K--) pow1(X,N[i]); //run function
		stop = clock(); //records the ticks at the end of the function call
		duration =((double)(stop-start))/CLK_TCK;//calculate duration for a single run of the function
		printf("%16lf",duration); //output duration
		end=clock(); 
		que[i]=((double)(end-begin))/CLK_TCK; //calculate Total Time for a repetition
	}
	printf("\nTotal Time:                     ");
	for(int i=0;i<8;i++){
		printf("%16lf",que[i]); //output each Total Time
	}
 
	K=1e7; //K stands for the number of times this function runs repeatedly 
    printf("\n\t\t\t\t\t\t\t\t\tAlgorithm2(interative version)  ");
    printf("\nK:                              ");
    for(int i=0;i<8;i++) printf("%16d",K);
    printf("\nDuration(e-7):                  ");
    for(int i=0;i<8;i++){
    	K=1e7;
    	begin=clock(); //records the ticks at the beginning of the function call
    	start = clock();
		while(K--) pow2_rec(X,N[i]);//run function
		stop = clock();//records the ticks at the end of the function call
		duration =((double)(stop-start))/CLK_TCK;//calculate duration for a single run of the function
		printf("%16lf",duration);//output duration
		end=clock();
		que[i]=((double)(end-begin))/CLK_TCK;//calculate Total Time for a repetition
	}
	printf("\nTotal Time:                     ");
	for(int i=0;i<8;i++){
		printf("%16lf",que[i]);//output each Total Time
	}

	K=1e7; //K stands for the number of times this function runs repeatedly 
    printf("\n\t\t\t\t\t\t\t\t\tAlgorithm2(interative version)  ");
    printf("\nK:                              ");
    for(int i=0;i<8;i++) printf("%16d",K);
    printf("\nDuration(e-7):                  ");
    for(int i=0;i<8;i++){
    	K=1e7;
    	begin=clock(); //records the ticks at the beginning of the function call
    	start = clock();
		while(K--) pow2_ite(X,N[i]);//run function
		stop = clock();//records the ticks at the end of the function call
		duration =((double)(stop-start))/CLK_TCK;//calculate duration for a single run of the function
		printf("%16lf",duration);//output duration
		end=clock();
		que[i]=((double)(end-begin))/CLK_TCK;//calculate Total Time for a repetition
	}
	printf("\nTotal Time:                     ");
	for(int i=0;i<8;i++){
		printf("%16lf",que[i]);//output each Total Time
	}
    return 0;
}
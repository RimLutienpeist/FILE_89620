#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

void f1(int n,int array[MAX][MAX],int prei);/*Function declaration*/
void f2(int n,int array[MAX][MAX],int prei);
void f3(int n,int array[MAX][MAX],int prei);

void prepare();/*do preparation work*/
void ChoiceGet();/*get your choice of function*/
void outcome();/*used to test the speed and output the outcome*/ 
void judge(int max,int ai,int aj,int bi,int bj,int num);/*judge the outcome of function and output the submatrix*/

clock_t start,stop;
double toltime;

void (*f)(int n,int array[MAX][MAX],int prei);/*define a function pointer*/
int array[MAX][MAX];/*define the matrix*/
int iteration=10000,N=10;/********designed iteration times and repetition which are used in 'outcome' function, tester can change it here********/

double averagetoltime[6]={0};/*record the average toltime time of matrixs of size 5,10,30,50,80,100*/
int n;/*the size of the matrix*/
int flag=1;/*used to make sure max submatrix is printed only once*/

int main(void)
{
	do
	{
		prepare();	
		ChoiceGet();
		outcome();
	}
	while(1);
}

void prepare()/*preparation work*/
{
	int i,j;/*row,colomn*/
	printf("Please tell me the size of the matrix, or you can input '0' to exit.\n");
	scanf("%d",&n);
	if(n==0)exit(0);
	printf("Please input the matrix which contains only integers\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&array[i][j]);
		}
	}
	
	printf("Please tell me the function you want to choose, input either '1', '2' or '3'.\n");
	printf("Function 1's time complexity is O(n^6),while function 2's time complexity is O(n^4), function 3 is O(n^3).\n");
}

void ChoiceGet()
{
	int choice;/*used to record the chosen test function*/
	do/*get the choice*/
	{
		printf("Enter a choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:f=&f1;break;
			case 2:f=&f2;break;
			case 3:f=&f3;break;
			default:printf("Invalid input!\n");
		}
	}
	while(choice!=1&&choice!=2&&choice!=3);
}

void outcome()/*deal with the outcome*/
{
	int i,j=0;
	double sum=0;/*used to caculate average running time*/
	for(;j<N;j++)
	{
		i=0; 
		start=clock();/*start the test*/
		for(;i<iteration;i++)/*run function iteration times*/
		{
			f(n,array,i);
		}
		stop=clock();
		toltime=double(stop-start)/CLK_TCK;
		sum+=toltime/iteration;
		printf("Iteration times:%-10d Ticks:%-8d Total time:%-10.5f toltime:%-10.8f\n",iteration,stop-start,toltime,toltime/iteration);/*print the outcome*/
	}
	flag=1;/*reset flag*/
	printf("Average time is %10.8f\n",sum/N);
}

void judge(int max,int ai,int aj,int bi,int bj,int array[MAX][MAX])
{
	if(!max&&!ai&&!aj&&!bi&&!bj&&array[0][0]<0)/*judge if all the integers are negative*/
	{
		printf("All the integers are negative!\n");
	}
	else
	{
		printf("Find it!\n");
		int i,j;
		for(i=ai;i<bi+1;i++)/*print the max submatrix*/
		{
			for(j=aj;j<bj+1;j++)
			{
				printf("%4d ",array[i][j]);
			}
			printf("\n");
		}
		printf("The maximum submatrix sum is %d.\n",max);/*print other information of the submatrix*/
		printf("Start from %d row,%d column, end at %d row,%d colomn.\n",ai+1,aj+1,bi+1,bj+1);/*plus 1 because the subscript start at 0.*/
	}
}

void f1(int n,int array[MAX][MAX],int prei)/*Time complexity is O(n^6)*/
{
	int starti,startj,finali,finalj;/*Flag Start Row, Start Column, End Row, End Column*/
	int row,column;/*Used to flag the designative matrix's row, column*/
	int sum,max=0;/*'sum' is used to caculate the designative matrix's sum, max is used to compare and record the max sum*/
	int ai=0,aj=0,bi=0,bj=0;/*They are used to record the max submatrix's Start Row, Start Column, End Row, End Column*/
	for(starti=0;starti<n;starti++)
	{
		for(startj=0;startj<n;startj++)
		{
			for(finali=starti;finali<n;finali++)
			{
				for(finalj=startj;finalj<n;finalj++)
				{
					sum=0;/*when finalj changes, sum is reset to 0*/
					for(row=starti;row<finali+1;row++)
					{
						for(column=startj;column<finalj+1;column++)
						{
							sum+=array[row][column];/*add*/
						}
					}
					if(sum>max)/*compare and record*/
					{
						max=sum;
						ai=starti;
						aj=startj;
						bi=finali;
						bj=finalj;
					}
				}
			}
		}
	}
	if(prei==iteration-1&&flag)
	{
		flag=0;
		judge(max,ai,aj,bi,bj,array);
	}
}

void f2(int n,int array[MAX][MAX],int prei)/*Time complexity is O(n^4)*/
{
	int starti,startj,finali,finalj;/*their function is the same as f1*/
	int sum,max=0;/*'sum' is used to caculate a row's numbers' sum which is different from f1, max is used to compare and record the max sum*/
	int ai=0,aj=0,bi=0,bj=0;/*their function is the same as f1*/
	int aux[MAX]={0};/*Auxiliary array, aux[j] records the sum of aik(starti<=i<=finali,startj<=k<=finalj)*/
	int i,j;
	for(starti=0;starti<n;starti++)
	{
		for(startj=0;startj<n;startj++)
		{
			for(finali=starti;finali<n;finali++)
			{
				sum=0;/*diffierent from f1,when finali changes,sum need to be reset*/
				for(finalj=startj;finalj<n;finalj++)
				{
					sum+=array[finali][finalj];/*'sum' is the sum of only a row's numbers*/
					aux[finalj]=sum+aux[finalj];/*record the auxiliary array*/
					if(aux[finalj]>max)
					{
						max=aux[finalj];
						ai=starti;
						aj=startj;
						bi=finali;
						bj=finalj;
					}
				}
			}
			for(i=0;i<n;i++)aux[i]=0;
		}
	}
	if(prei==iteration-1&&flag)
	{
		flag=0;
		judge(max,ai,aj,bi,bj,array);
	}
}


void f3(int n,int array[MAX][MAX],int prei)
{
	int i,j;
	int starti,prej,possibleN;/*start row,present colomn,and possible number of rows of the max submatrix*/
	int aux[MAX][MAX]={0};
	int sum,max=0,p;/*p is used to label the sumatrix's start colomn*/
	int ai=0,aj=0,bi=0,bj=0;/*their function is the same as f1*/
	for(i=0;i<n;i++)/*get the auxiliary array, aux[i][j] records the sum of array[0][j],array[1][j]...array[i][j]*/
	{
		for(j=0;j<n;j++)
		{
			if(i==0)
				aux[i][j]=array[i][j];/*the first row is itself*/
			else 
				aux[i][j]=array[i][j]+aux[i-1][j];
		}
	}
	for(possibleN=1;possibleN<n+1;possibleN++)/*first, guess possible number of rows of the max submatrix*/
	{
		for(starti=0;starti+possibleN<n+1;starti++)/*secend, list all possible start row while the number of rows is possibleN*/
		{
			sum=0;
			p=0;
			for(prej=0;prej<n;prej++)/*Compress possibleN rows into one dimension and deal with them as one dimension array*/
			{
				if(starti==0)
				{
					sum+=aux[starti+possibleN-1][prej];
				}
				else
				{
					sum+=aux[starti+possibleN-1][prej]-aux[starti-1][prej];
				}
				if(sum>max)
				{
					max=sum;
					ai=starti;
					aj=p;
					bi=starti+possibleN-1;
					bj=prej;
				}
				if(sum<0)/*if sum is 0, it means it can only bring negative effects*/
				{
					sum=0;
					p=prej+1;/*p is used to label the sumatrix's start colomn*/
				}
			}
		}
	}
	if(prei==iteration-1&&flag)
	{
		flag=0;
		judge(max,ai,aj,bi,bj,array);
	}
}

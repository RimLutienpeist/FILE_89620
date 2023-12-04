#include <stdio.h>

void search ( int a[], int len );

int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n];
    for ( int i=0; i<n; i++ ) {
        scanf("%d", &a[i]);
    }
    
    search(a, n);

    for ( int i=0; i<n; i++ ) {
        printf("%d\n", a[i]);
    }
}

/* 请在这里填写答案 */

void sss(int a[],int begin,int end);

void search ( int a[], int len ){
    sss(a,0,len-1);
}

void sss(int a[],int begin,int end){
    if(begin >= end){
        return;
    };

    int val = a[begin],flag = 0;
    int *L = &a[begin],*R = &a[end];

    while(R != L){
        while(*R>=val && R!=L){
            R--;
        };
        *L = *R;

        while(*L<=val && R!=L){
            L++;
            flag++;
        };
        *R = *L;    
    };

    *L = val;

    sss(a,begin,begin+flag-1);
    sss(a,begin+flag+1,end);
}


// int partition( int a[], int left, int right )
// {
// 	int i=left;
// 	int j=right;
// 	int temp=0;
// 	while(i<j)
// 	{
// 		while(i<j && a[i]<a[j])
// 			j--;
// 		if(i<j)
// 		{
// 			temp=a[i];
// 			a[i]=a[j];
// 			a[j]=temp;
// 			i++;
// 		}
// 		while(i<j && a[i]<a[j])
// 			i++;
// 		if(i<j)
// 		{
// 			temp=a[i];
// 			a[i]=a[j];
// 			a[j]=temp;
// 			j--;
// 		}
// 	}
// 	return i;

// }
// #include<stdio.h>
// #include<math.h>
// #include<stdlib.h>

// typedef struct {
//     int position;
//     int count;
// }   POINT;

// POINT search(int n,int h,int* balloon){
//     POINT result;
//     result.count = 0;
//     result.position = 0;
//     int count = 0;
//     int end = balloon[n-1]-h;
//     int d = balloon[0];

//     for(;d<end;d++){
//         count = 0;
//         for(int j = 0;j<=n;j++){
//             int depa = balloon[j] - d;
//             if(depa <= h && depa >= 0){
//                 count++;
//             }else if(depa > h){
//                 break;
//             };
//         }; 

//         if(count > result.count){
//             result.count = count;
//             result.position = d;
//         };
//     };

//     return result;

// }

// int main(){
//     int 
//     n = 0,
//     h = 0;

//     scanf("%d %d",&n,&h);

//     int* balloon = (int*)malloc(sizeof(int) * n);

//     for(int i = 0;i<n;i++){
//         scanf("%d",&balloon[i]);
//     };

//     POINT result = search(n,h,balloon);

//     printf("%d %d",result.position,result.count);

//     free(balloon);

//     return 0;
// }

#include <stdio.h>


int main() {
    int n = 0, h = 0,i = 0,index = 0,k = 0,maxn = 0,minp = 0;

    scanf("%d %d", &n, &h);

    int* balloon = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &balloon[i]);
    };

    for(i = 0;i<n;i++){
        int pos = balloon[n-i-1];
        for(k = 1;i+k+1 <= n && pos-balloon[n-i-1-k] <= h;k++);
        if(k >= maxn){
            maxn = k;
            minp = pos-h;
        };
    };

    printf("%d %d", minp, maxn);

    free(balloon);

    return 0;
}
// #include<stdio.h>

// void END(int i){
//     if(i){
//         printf("YES\n");
//     }else{
//         printf("NO\n");
//     }
// }

// int main(){
//     int M = 0,N = 0,K = 0;

//     scanf("%d %d %d",&M,&N,&K);

//     int input[N],stack[M];

// end:
//     while(K--){
//         for(int i = 0;i<N;i++) scanf("%d",&input[i]);
        
//         for(int i = 0;i<N-M;i++){
//             if(input[i]>M+i){
//                 END(0);
//                 goto end;
//             }
//         }

//         for(int i = N-M+1;i<N-2;i++){
//             if(input[i] != (input[i+1] + 1) && input[i] != (input[i+1] -1)){
//                 if(input[i+1] < input[i+2]){
//                     END(0);
//                     goto end;                
//                 }
//             }
            
//         }

//         END(1);
//     }

//     return 0;
// }


#include<stdio.h>
#define MAX 1000

int main(){
    int M = 0,N = 0,K = 0;

    scanf("%d %d %d",&M,&N,&K);

    int input[N],stack[MAX+1],init[MAX+1];
    stack[0] = -1;
    for(int i = 0;i<MAX+1;i++) init[i] = i;

    int i = 0,flag = 1,j = 0,k = 0;
    while(K--){
        flag = 1;
        j = 0;
        k = 0;

        for(i = 0;i<N;i++) scanf("%d",&input[i]);

        for(i = 0;i<N;i++){
            while(stack[j]<input[i]){
                j++;
                k++;
                stack[j] = init[k];
            }

            if(j>M){
                flag = 0;  
                goto print;
            } 

            if(stack[j]!=input[i]){
                flag = 0;  
                goto print;
            }

            j--;
        }
print:
        if(flag){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}
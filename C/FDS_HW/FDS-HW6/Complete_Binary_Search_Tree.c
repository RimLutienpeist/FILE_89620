#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000

int CBT[MAXN] = {-1};
int l = 0;

void inorder(int root,int N,int input[]){
    if(root<=N){
        inorder(2*root,N,input);
        CBT[root]=input[l++];
        inorder(2*root+1,N,input);
    }
}

int cmp(const void* a, const void* b){
    return *(int*) a - *(int*) b;
}

int main(){
    int N = 0, i=0;

    scanf("%d",&N);
    int input[N];
    for(i = 0; i < N; i++) scanf("%d", &input[i]);

    qsort(input,N,sizeof(int),cmp);
    inorder(1,N,input);

    printf("%d",CBT[1]);
    for(i=2;i<=N;i++){
        printf(" %d",CBT[i]);
    }

    return 0;
}


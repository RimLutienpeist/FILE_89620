#include<stdio.h>

int N = 0;

int Find(int X, int* U){
    // printf("\n\nFinding\n\n");
    int root = X;
    for(;U[root]>0;root=U[root]);
    return root;
}

void inputCon(int* U){
    // printf("\n\ninputConing\n\n");

    int a,b,aR,bR;
    scanf("%d %d",&a,&b);
    aR = Find(a, U);
    bR = Find(b, U);
    if(U[aR]<U[bR]){
        U[aR] += U[bR];
        U[bR] = aR;
    }else{
        U[bR] += U[aR];
        U[aR] = bR;
    }
}

void checkCon(int* U){
    // printf("\n\ncheckConing\n\n");

    int a,b,aR,bR;
    scanf("%d %d",&a,&b);
    aR = Find(a,U);
    bR = Find(b,U);
    if(aR == bR) printf("yes\n");
    else printf("no\n");
}

void numOfCon(int *U){
    // printf("\n\ninputConing\n\n");


    int k = 0, numR = 0;
    for(int i = 1;i<N+1;i++){
        if(U[i] < 0){
            numR++;
            if(U[i] != -1) k = -U[i];
        }
    }

    if(numR>1) printf("There are %d components.",N-k+1);
    else printf("The network is connected.");
}

int main(){
    char M;
    scanf("%d",&N);
    int U[N+1];
    for(int i = 0;i<N+1;i++) U[i] = -1;

    scanf("%c",&M);
    while(scanf("%c",&M)){
        if(M=='\n') scanf("%c",&M);
        switch (M){
            case 'I': inputCon(U); break;
            case 'C': checkCon(U); break;
            default: break;
        }
        if(M=='S') break;
    }

    numOfCon(U);
    return 0;
}
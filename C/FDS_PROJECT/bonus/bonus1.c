#include<stdio.h>

int main(){
    int N,x=-1,y=-1;
    scanf("%d", &N);
    getchar();
    int q1[N];
    int q2[N];
    for(int i=0;i<N;i++){
        char op;
        scanf("%c",&op);
        if(op=='I'){
            int elem;
            scanf("%d",&elem);
            getchar();
            q1[++x]=elem;
        }else if(op=='O'){
            getchar();
            int time = 0;
            if(y==-1&&x==-1){
                printf("ERROR\n");
            }else{
                if(y==-1)
                    while(x>=0){
                        q2[++y]=q1[x--];
                        time+=2;
                    }
                printf("%d %d",q2[y--],++time);
                if(i!=N-1) printf("\n");
            }
        }
    }
}
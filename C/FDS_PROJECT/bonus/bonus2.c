#include<stdio.h>

int Minm(int recrec[], int record[],int M){
    int i,minm=0;
    for(i=0;i<M;i++){
        if(recrec[i]){
            if(!recrec[minm]) minm=i;
            if(record[i]<=record[minm]){
                minm = i;
            }
        }
    }
    return minm;
}

int main(){
    int N,M,i,r=0,j=0,mindex=0,temp = -100000,m,n,k;
    scanf("%d %d", &N,&M);
    m=M;n=N-M;
    int record[M];
    int recrec[M];
    int run[N][N];
    int runcal[N];
    for(i=0;i<N;i++) runcal[i] = 0;
    for(i=0;i<M;i++) recrec[i] = 1;
    for(i=0;i<M;i++) scanf("%d",&record[i]);
    for(i=0;i<N;i++){
        int p = Minm(recrec,record,M);
        mindex = record[p]>=temp ? p : -1;
        if(mindex==-1){
            recrec[p] = 0;
            p=Minm(recrec,record,M);
            mindex = p;
            m--;
        }
        if(!m){
            r++;
            j=0;
            m=M;
            for(k=0;k<M;k++) recrec[k] = 1;
        }
        temp = record[mindex];
        runcal[r]++;
        run[r][j++] = temp;
        if(i<n) scanf("%d",&record[mindex]);
            else record[mindex] = -10000;
    }

    i=0;
    while(runcal[i]!=0){
        printf("%d",run[i][0]);
        for(j=1;j<runcal[i];j++)
            printf(" %d",run[i][j]);
        if(record[++i]) printf("\n");
    }
    return 0;
}
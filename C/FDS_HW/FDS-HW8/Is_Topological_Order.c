#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 1 to MaxVertexNum */

typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

bool IsTopSeq( LGraph Graph, Vertex Seq[] );

int main()
{
    int i, j, N;
    Vertex Seq[MaxVertexNum];
    LGraph G = ReadG();
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        for (j=0; j<G->Nv; j++)
            scanf("%d", &Seq[j]);
        if ( IsTopSeq(G, Seq)==true ) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}

/* Your function will be put here */


bool IsTopSeq( LGraph Graph, Vertex Seq[] )
{   
    Vertex CheckingOrder[MaxVertexNum];
    int Indegree[MaxVertexNum], cnt=0, ocnt = 0;
    Vertex V;
    PtrToAdjVNode W;
 
    for (V=0; V<Graph->Nv; V++)
        Indegree[V] = 0;
        
    for (V=0; V<Graph->Nv; V++)
        for (W=Graph->G[V].FirstEdge; W; W=W->Next)
            Indegree[W->AdjV]++; 

    for (V=0; V<Graph->Nv; V++)
        if ( Indegree[V]==0 ){
            CheckingOrder[ocnt++] = V;
            cnt++;
        }

    /* 下面进入拓扑排序 */ 
    while( cnt != Graph->Nv){
        for(int i = cnt-ocnt;i<cnt;i++){
            int flagi = 1;
            for(int j = 0;j<ocnt;j++)
                if(Seq[i]==CheckingOrder[j]) flagi = 0;
            if(flagi) return false;
        }
        ocnt = 0;
        for ( W=Graph->G[V].FirstEdge; W; W=W->Next )
            if ( --Indegree[W->AdjV] == 0 ){/* 若删除V使得W->AdjV入度为0 */
                CheckingOrder[ocnt++] = W->AdjV;
                cnt++;
            }
    } /* while结束*/

    return true;
}

/* Your function will be put here */

// bool IsTopSeq( LGraph Graph, Vertex Seq[] ) {
//     int Indegree[MaxVertexNum];
//     int i, j;
//     PtrToAdjVNode p;

//     /* Initialize Indegree array */
//     for (i = 0; i < Graph->Nv; i++)
//         Indegree[i] = 0;

//     /* Calculate the indegree of each vertex */
//     for (i = 0; i < Graph->Nv; i++) {
//         p = Graph->G[i].FirstEdge;
//         while (p) {
//             Indegree[p->AdjV]++;
//             p = p->Next;
//         }
//     }

//     /* Check if Seq corresponds to a topological order */
//     for (i = 0; i < Graph->Nv; i++) {
//         if (Indegree[Seq[i]] != 0)
//             return false;  // Seq does not correspond to a topological order
//         p = Graph->G[Seq[i]].FirstEdge;
//         while (p) {
//             Indegree[p->AdjV]--;
//             p = p->Next;
//         }
//     }

//     return true;  // Seq corresponds to a topological order
// }

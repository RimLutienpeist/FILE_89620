#include<stdio.h>
#define MAXN 10000;

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
    int key;
    BinTree Left;
    BinTree Right;
    // int color; 
};

int color[MAXN] = {-1};   //color=1 --> red, color=0 --> black. 

BinTree BuildTree(int n); 
BinTree Insert(BinTree T, int X);   //build a BST from inputs

int IsRBT(BinTree T);   //the function determines whether the tree is red-black or not
int ChiAreBla(BinTree T);   //check if the children of a red node are whether both black or not
int SameBlaNode(BinTree T); //check that all simple paths from the node to descendant leaves contain the same number of black nodes.
// int Is = 0; //be used if function IsRBT(), Is=0 --> not RBT, Is=1 --> is RBT

int abs(int n){     //just an absolute value function
    int bits = sizeof(int) * 8 - 1;
    return (n^(n>>bits)) - (n>>bits);
}

int main(){
    int K = 0,N = 0;
    scanf("%d",&K);

    for(int i = 0;i<K;i++){ //check every tree, one by one
        scanf("%d",&N);
        BinTree T = (BinTree)malloc(N*sizeof(struct TreeNode));
        T = BuildTree(N);
        int p = IsRBT(T);   //YES --> p=1, NO --> p=0.
        if(p)
            if(i == K-1) printf("Yes"); //to make no '\n' after the last one output
            else printf("Yes\n");
        else
            if(i == K-1) printf("No");  //to make no '\n' after the last one output
            else printf("No\n");
        free(T);
    }

    return 0;
}


BinTree BuildTree(int n){
    BinTree T = NULL;
    for(int i = 0;i<n;i++){ 
        int x = 0;
        scanf("%d",&x); //x is the key of one node
        T = Insert(T,x);
    }
    return T;
}


BinTree Insert(BinTree T, int X){
    if(!T){ //reach the leaf node
        T = (BinTree)malloc(sizeof(struct TreeNode));
        if(X>0) color[T->key] = 0;   //black node
            else color[T->key] = 1;  //red node
        T->key = abs(X);    //abs is to get the absolute value of X 
        T->Left = T->Right = NULL;  //creat new leaf;
    }else{ 
        if(X <= T->key)
            T->Left = Insert(T->Left,X);    //enter the left subtree
        else  if(X > T->key)
            T->Right = Insert(T->Right,X);  //enter the right subtree
    }
    return T;
}


int IsRBT(BinTree T){
    if(color[T->key] == 1) return 0; //if root is red
    int p = Traversal(T);
    return p;
}

int Traversal(BinTree T){
    if(ChiAreBla(T)) return 0;
    if(SameBlaNode(T)) return 0;

    if(!(Traversal(T->Left))) return 0;
    if(!(Traversal(T->Right))) return 0;

    return 1;
}

int ChiAreBla(BinTree T){
    if(T->color == 1)
        if(T->Left->color == 1  
            || T->Right->color == 1) return 0;  //if the children of a red node have red one

    return 1;   //the children of a red node are both black
}
int SameBlaNode(BinTree T){
    return 1;
}

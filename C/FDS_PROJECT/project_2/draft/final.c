#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
    int key;
    BinTree Left;
    BinTree Right;
    int color; //color=1 --> red, color=0 --> black. 
};

BinTree BuildTree(int n); 
BinTree Insert(BinTree T, int X);   //build a BST from inputs
void freeTree(BinTree root); //free memory of tree
int isRedBlackTree(BinTree T, int blackCount, int* pathBlackCount); //judge the tree T is red-black tree or not


int abs(int n){     //just an absolute value function
    int bits = sizeof(int) * 8 - 1;
    return (n^(n>>bits)) - (n>>bits);
}


int main() {
    int K = 0,N = 0;
    scanf("%d",&K);
    while (K--){    //check every tree, one by one   
        scanf("%d",&N);
        BinTree T = (BinTree)malloc(N*sizeof(struct TreeNode));
        T = BuildTree(N);

        int pathBlackCount = 0;
        if (
            T == NULL 
            || (T->color == 1) 
            || !isRedBlackTree(T, 0, &pathBlackCount)
        )
            if(K==0) printf("No"); //to make no '\n' after the last one output
            else printf("No\n");
        else
            if(K==0) printf("Yes");   //to make no '\n' after the last one output
            else printf("Yes\n");

        freeTree(T);    //free memory of this tree
    }

    return 0;
}


BinTree BuildTree(int n){
    BinTree T = NULL;
    int x = 0;
    for(int i = 0;i<n;i++){ 
        scanf("%d",&x); //x is the key of one node
        T = Insert(T,x);
    }
    return T;
}


BinTree Insert(BinTree T, int X){
    if(!T){ //reach the leaf node
        T = (BinTree)malloc(sizeof(struct TreeNode));

        if(X>0) T->color = 0;   //black node
        else T->color = 1;  //red node

        T->key = abs(X);    //abs is to get the absolute value of X 
        T->Left = T->Right = NULL;  //creat new leaf;
    }else{ 
        if(X < T->key)
            T->Left = Insert(T->Left,X);    //enter the left subtree
        else 
            T->Right = Insert(T->Right,X);  //enter the right subtree
    }
    return T;
}

// free memory
void freeTree(BinTree T) {
    if (!T) return;

    // free the memory, begin from the leaf node
    freeTree(T->Left);
    freeTree(T->Right);
    free(T);    
}

// Red-Black-Tree judge fuction
int isRedBlackTree(BinTree T, int blackCount, int* pathBlackCount) {
    if (T == NULL) {
        (*pathBlackCount)++;    //as every leaf (NULL) is black (property 3)
        return 1;
    }

    //test property 4: If a node is red(1), then both its children are black(0).
    if (T->color == 1)
        if (
            (T->Left && T->Left->color == 1) 
            || (T->Right && T->Right->color == 1)
        )
            return 0;

    //count the number of black nodes in the path of the left and right subtrees of the current node
    int leftPathBlackCount = 0, rightPathBlackCount = 0;
    int leftIsRedBlack = isRedBlackTree(T->Left, blackCount, &leftPathBlackCount);
    int rightIsRedBlack = isRedBlackTree(T->Right, blackCount, &rightPathBlackCount);

    /* test property 5: For each node, all simple paths from the node to descendant leaves
     contain the same number of black nodes. */
    if (leftIsRedBlack && rightIsRedBlack && leftPathBlackCount == rightPathBlackCount){
        *pathBlackCount = T->color == 0 ? leftPathBlackCount + 1 : leftPathBlackCount;  //we need to add the current node if it is black
        return 1;
    }else{
        return 0;
    }
}


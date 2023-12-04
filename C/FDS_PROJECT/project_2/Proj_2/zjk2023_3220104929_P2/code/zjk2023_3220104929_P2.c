#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *BinTree;
struct TreeNode{
    int key;
    BinTree Left;
    BinTree Right;
    int color; //color=1 --> red, color=0 --> black. 
};

BinTree BuildTree(int N); 
BinTree createNode(int key, int color);
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

    //build tree 
        scanf("%d", &N);
        BinTree T = NULL;
        T = BuildTree(N);

    //judge tree
        int pathBlackCount = 0; //count the black node of the path from a node to its leaf node
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


BinTree BuildTree(int N){
        BinTree T = NULL;
        int key = 0, color = 0;
        for (int i = 0; i < N; ++i) {

            //scan key and color of each node
            scanf("%d", &key);
            if (key < 0) {
                color = 1;  //red node
                key = -key;  //absolute value
            } else {
                color = 0;  //black node
            }

            //insert new node into the tree
            if (!T) {
                T = createNode(key, color); //creat root
            }else{  //creat son node
                BinTree current = T;    //the current node
                BinTree parent = NULL;  //the parent of current node, after the current enter its subtree

                //let current reach the leaf node of the BST, while recording its parent
                while (current != NULL) {
                    parent = current;
                    if (key < current->key)
                        current = current->Left;
                    else
                        current = current->Right;
                }

                //insert the new node of the BST
                if (key < parent->key)
                    parent->Left = createNode(key, color);
                else
                    parent->Right = createNode(key, color);
            }
        }

    return T;
}


BinTree createNode(int key, int color) {
    BinTree newNode = (BinTree)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->Left = NULL;
    newNode->Right = NULL;
    newNode->color = color;
    return newNode;
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

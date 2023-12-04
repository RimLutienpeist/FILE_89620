#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* newNode(int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node* buildTree(int inorder[], int postorder[], int n) {
    if (n <= 0) return NULL;

    Node* root = newNode(postorder[n-1]);

    int rootIndex;
    for (rootIndex = 0; rootIndex < n; rootIndex++) {
        if (inorder[rootIndex] == postorder[n-1]) break;
    }

    root->left = buildTree(inorder, postorder, rootIndex);
    root->right = buildTree(inorder + rootIndex + 1, postorder + rootIndex, n - rootIndex - 1);
  
    return root;
}

void printZigZag(Node* root, int n) {
    if (root == NULL) return;

    Node** stack1 = (Node**) malloc(n*sizeof(Node*));
    Node** stack2 = (Node**) malloc(n*sizeof(Node*));
    int top1 = 0, top2 = 0;

    stack1[top1++] = root;
    int isFirst = 1;

    while (top1 > 0 || top2 > 0) {
        while (top1 > 0) {
            Node* current = stack1[--top1];

            if (!isFirst) printf(" ");
            printf("%d", current->key);
            isFirst = 0;

            if (current->right != NULL) stack2[top2++] = current->right;
            if (current->left != NULL) stack2[top2++] = current->left;
        }

        while (top2 > 0) {
            Node* current = stack2[--top2];

            if (!isFirst) printf(" ");
            printf("%d", current->key);
            isFirst = 0;

            if (current->left != NULL) stack1[top1++] = current->left;
            if (current->right != NULL) stack1[top1++] = current->right;
        }
    }

    free(stack1);
    free(stack2);
}
int main() {
    int n;
    scanf("%d", &n);

    int* inorder = (int*) malloc(n*sizeof(int));
    int* postorder = (int*) malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    Node* root = buildTree(inorder, postorder, n);
    printZigZag(root, n);

    free(inorder);
    free(postorder);

    return 0;
}
// 请生成相应的C语言代码，请注意，在确定了二叉树后需要锯齿状输出，比如第一层是从左到右输出，第二层是从右到左输出，请三层又是从左到右输出，以此类推。
// Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences. 
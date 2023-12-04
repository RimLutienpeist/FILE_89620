#include <stdio.h>
#include <stdlib.h>

// 定义红黑树节点结构
typedef struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
    char color;  // 'b'表示黑色，'r'表示红色
} TreeNode;

// 创建新节点
TreeNode* createNode(int key, char color) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->color = color;
    return newNode;
}

// 释放树的内存
void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 判断是否是红黑树
int isRedBlackTree(TreeNode *root, int blackCount, int* pathBlackCount) {
    if (root == NULL) {
        // 空节点被视作黑节点，路径上的黑节点数加一
        (*pathBlackCount)++;
        return 1;
    }

    // 对红黑树的性质进行验证
    if (root->color == 'r') {
        // 如果当前节点为红色，则其子节点必须为黑色
        if ((root->left && root->left->color == 'r') || (root->right && root->right->color == 'r')) {
            return 0;
        }
    }

    // 统计左子树和右子树的路径上黑节点的数量
    int leftPathBlackCount = 0, rightPathBlackCount = 0;
    int leftIsRedBlack = isRedBlackTree(root->left, blackCount, &leftPathBlackCount);
    int rightIsRedBlack = isRedBlackTree(root->right, blackCount, &rightPathBlackCount);

    // 当前节点到叶子节点的路径上黑节点数量相等
    if (leftIsRedBlack && rightIsRedBlack && leftPathBlackCount == rightPathBlackCount) {
        *pathBlackCount = root->color == 'b' ? leftPathBlackCount + 1 : leftPathBlackCount;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int K, N;
    scanf("%d", &K);
    while (K--) {
        scanf("%d", &N);
        TreeNode *root = NULL;
        int i, key;
        char color;
        for (i = 0; i < N; ++i) {
            scanf("%d", &key);
            if (key < 0) {
                color = 'r';  // 红色节点
                key = -key;  // 取绝对值
            } else {
                color = 'b';  // 黑色节点
            }
            // 插入节点到红黑树中
            if (root == NULL) {
                root = createNode(key, color);
            } else {
                TreeNode *current = root;
                TreeNode *parent = NULL;
                while (current != NULL) {
                    parent = current;
                    if (key < current->key) {
                        current = current->left;
                    } else {
                        current = current->right;
                    }
                }
                if (key < parent->key) {
                    parent->left = createNode(key, color);
                } else {
                    parent->right = createNode(key, color);
                }
            }
        }
        int pathBlackCount = 0;
        if (root == NULL || (root->color != 'b') || !isRedBlackTree(root, 0, &pathBlackCount)) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
        // 释放树的内存
        freeTree(root);
    }
    return 0;
}
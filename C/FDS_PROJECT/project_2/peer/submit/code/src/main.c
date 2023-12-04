#include <stdio.h>
#include <string.h>

#define INF 99999999

// Define global variables
int K, N;
int node[35][3];  // Tree node information, each node has value and left and right children
int color[35];    // Node color, 0 for black, 1 for red

// Insert a node into the tree
void Insert(int root, int a) {
    if (node[a][0] <= node[root][0]) {  // If the value of the node to be inserted is less than or equal to the value of the current node
        if (node[root][1])                // If the current node has a left child
            Insert(node[root][1], a);     // Recursively insert into the left subtree
        else
            node[root][1] = a;            // Otherwise, set it as the left child of the current node
    } else {
        if (node[root][2])                // If the current node has a right child
            Insert(node[root][2], a);     // Recursively insert into the right subtree
        else
            node[root][2] = a;            // Otherwise, set it as the right child of the current node
    }
}

// Check if the properties of a red-black tree are satisfied
int Judge(int root) {
    if (!node[root][1] && !node[root][2]) {  // If it is a leaf node
        if (!color[root])                     // If it is a black node
            return 1;                         // Return height 1
        else
            return 0;                         // Otherwise, return height 0
    }

    if (color[root]) {                        // If the current node is red
        if (color[node[root][1]] || color[node[root][2]])  // If the child nodes have red nodes
            return -1;                       // Return -1 indicating adjacent red nodes
    }

    int lc = 0, rc = 0;

    if (node[root][1]) {                      // If there is a left child
        lc = Judge(node[root][1]);            // Recursively check the left subtree
        if (lc < 0)
            return -1;                        // If the left subtree does not satisfy the red-black tree property, directly return -1
    }

    if (node[root][2]) {                      // If there is a right child
        rc = Judge(node[root][2]);            // Recursively check the right subtree
        if (rc < 0)
            return -1;                        // If the right subtree does not satisfy the red-black tree property, directly return -1
    }

    if (lc == rc)
        return lc + !color[root];             // If the heights of the left and right subtrees are equal, return the height of the left subtree plus the color of the current node (0 or 1)
    else
        return -1;                            // Otherwise, return -1 indicating that the red-black tree property is not satisfied
}

int main(void) {
    scanf("%d", &K);  // Input the number of test cases
    for (int k = 0; k < K; k++) {
        scanf("%d", &N);  // Input the number of nodes for the current test case
        int flag = 0;
        int data;
        memset(node, 0, sizeof(node));  // Initialize the tree node information
        memset(color, 0, sizeof(color));  // Initialize the node colors
        for (int i = 0; i < N; i++) {
            scanf("%d", &data);
            if (data < 0) {
                if (i == 0)
                    flag = 1;               // If the first node is red, set the flag to 1
                node[i][0] = -data;         // Store the node value (remove the negative sign)
                color[i] = 1;               // Mark the node as red
            } else {
                node[i][0] = data;          // Store the node value
            }
            if (i)
                Insert(0, i);             // Insert the current node into the tree
        }
        if (flag || Judge(0) == -1)
            printf("No\n");               // Output "No" indicating that the red-black tree property is not satisfied
        else
            printf("Yes\n");              // Output "Yes" indicating that the red-black tree property is satisfied
    }
    return 0;
}

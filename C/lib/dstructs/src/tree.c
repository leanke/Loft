#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Inserts a new node into the binary tree (BST)
TreeNode* insertNode(TreeNode* root, int val) {
    if (!root) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->value = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (val < root->value) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

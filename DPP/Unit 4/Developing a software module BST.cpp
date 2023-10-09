
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int isBST(struct TreeNode* root, long long minVal, long long maxVal) {
    if (root == NULL) {
        return 1; 
    }

    if (root->val <= minVal || root->val >= maxVal) {
        return 0; 
    }

    return isBST(root->left, minVal, root->val) && isBST(root->right, root->val, maxVal);
}

struct TreeNode* buildTree() {
    int val;
    scanf("%d", &val);
    if (val == -1) {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main() {
    struct TreeNode* root = buildTree();
    if (isBST(root, LLONG_MIN, LLONG_MAX)) {
        printf("The given binary tree is a BST\n");
    } else {
        printf("The given binary tree is not a BST\n");
    }
    return 0;
}
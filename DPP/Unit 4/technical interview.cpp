#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void kthLargestUtil(TreeNode* root, int& k, int& result) {
    if (!root || k == 0) {
        return;
    }

    // Traverse the tree in reverse inorder (right, root, left) to find the kth largest element
    kthLargestUtil(root->right, k, result);
    k--;

    if (k == 0) {
        result = root->val;
        return;
    }

    kthLargestUtil(root->left, k, result);
}

int kthLargest(TreeNode* root, int k) {
    int result = -1;
    kthLargestUtil(root, k, result);
    return result;
}

TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

int main() {
    int val;
    TreeNode* root = nullptr;

    // Input values to create the BST
    while (cin >> val && val != -1) {
        root = insert(root, val);
    }

    int k;
    cin >> k;

    int kth_largest = kthLargest(root, k);

    cout << kth_largest << endl;

    return 0;
}

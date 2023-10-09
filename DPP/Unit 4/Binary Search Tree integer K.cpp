#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int kthSmallest(TreeNode* root, int& k) {
    if (!root) {
        return -1; // Invalid case
    }
    
    // Inorder traversal to find kth smallest element
    int leftVal = kthSmallest(root->left, k);
    
    if (leftVal != -1) {
        return leftVal;
    }
    
    k--;
    
    if (k == 0) {
        return root->val; // Found the kth smallest element
    }
    
    return kthSmallest(root->right, k);
}

int main() {
    int root_val;
    cin >> root_val;

    TreeNode* root = new TreeNode(root_val);

    // Build the BST
    int val;
    while (cin >> val && val != -1) {
        TreeNode* newNode = new TreeNode(val);
        TreeNode* current = root;
        
        while (true) {
            if (val < current->val) {
                if (current->left) {
                    current = current->left;
                } else {
                    current->left = newNode;
                    break;
                }
            } else {
                if (current->right) {
                    current = current->right;
                } else {
                    current->right = newNode;
                    break;
                }
            }
        }
    }

    int k;
    cin >> k;

    int kth_smallest = kthSmallest(root, k);
    cout << kth_smallest << endl;

    return 0;
}

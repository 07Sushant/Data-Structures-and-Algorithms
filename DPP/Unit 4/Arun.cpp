#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    } else {
        if (root->val < key) {
            root->right = insert(root->right, key);
        } else {
            root->left = insert(root->left, key);
        }
    }
    return root;
}

void search(TreeNode* root, int key) {
    if (root == nullptr || root->val == key) {
        if (root == nullptr) {
            std::cout << key << " is not present in the BST" << std::endl;
        } else {
            std::cout << key << " is present in the BST" << std::endl;
        }
    } else if (root->val < key) {
        search(root->right, key);
    } else {
        search(root->left, key);
    }
}

int main() {
    TreeNode* root = nullptr;
    int value;

    while (true) {
        std::cin >> value;
        if (value == -1) {
            break;
        }
        root = insert(root, value);
    }

    int search_value;
    std::cin >> search_value;
    search(root, search_value);

    return 0;
}

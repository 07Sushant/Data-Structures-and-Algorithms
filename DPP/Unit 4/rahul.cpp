#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to perform preorder traversal and print the tree
void preorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to convert a binary tree to its mirror image
void mirrorTree(Node* root) {
    if (root == nullptr)
        return;

    // Swap the left and right subtrees of the current node
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively convert the left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    // Build the binary tree
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (root == nullptr) {
            root = new Node(value);
        } else {
            Node* current = root;
            while (true) {
                if (value < current->data) {
                    if (current->left == nullptr) {
                        current->left = new Node(value);
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == nullptr) {
                        current->right = new Node(value);
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    cout << "Original tree: ";
    preorderTraversal(root);
    cout << endl;

    // Convert the tree to its mirror image
    mirrorTree(root);

    cout << "Mirror Image: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}

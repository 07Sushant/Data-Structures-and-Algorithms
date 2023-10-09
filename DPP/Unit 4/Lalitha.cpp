#include <iostream>
#include <vector>
using namespace std;

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to construct the binary tree from the given array
Node* constructBinaryTree(vector<int>& values, int index, int n) {
    if (index >= n) {
        return nullptr;
    }
    Node* root = new Node(values[index]);
    root->left = constructBinaryTree(values, 2 * index + 1, n);
    root->right = constructBinaryTree(values, 2 * index + 2, n);
    return root;
}

// Function to perform post-order traversal and print the values
void postOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    cin >> n;

    vector<int> values(n);

    // Read the values representing the binary tree
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // Construct the binary tree from the given array
    Node* root = constructBinaryTree(values, 0, n);

    // Perform post-order traversal and print the values
    postOrderTraversal(root);
    cout << endl;

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to count the number of nodes in the binary tree
int nodeCount(struct Node *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + nodeCount(root->left) + nodeCount(root->right);
}

// Function to create a new binary tree node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build a binary tree 
struct Node *buildBinaryTree() {
    int data;
    scanf("%d", &data);

    if (data == -1) {
        return NULL;  // Return NULL for an empty node
    }

    struct Node *root = createNode(data);

    root->left = buildBinaryTree();
    root->right = buildBinaryTree();

    return root;
}

// Function to check if a binary tree has duplicate values
bool hasDuplicateValuesUtil(struct Node *root, int *prev_values, int *prev_index) {
    if (root == NULL) {
        return false;
    }

    // Check if the current node's data matches any previous value.
    for (int i = 0; i < *prev_index; i++) {
        if (prev_values[i] == root->data) {
            return true;
        }
    }

    // Store the current node's data in the array of previous values.
    prev_values[(*prev_index)++] = root->data;

    // Recursively check for duplicate values in left and right subtrees.
    return hasDuplicateValuesUtil(root->left, prev_values, prev_index) ||
           hasDuplicateValuesUtil(root->right, prev_values, prev_index);
}

bool hasDuplicateValues(struct Node *root) {
    int prev_index = 0;
    int numNodes = nodeCount(root);

    int *prev_values = (int *)malloc(numNodes * sizeof(int)); // Dynamically allocate memory

    bool result = hasDuplicateValuesUtil(root, prev_values, &prev_index);

    free(prev_values); // Free dynamically allocated memory

    return result;
}

int main() {
    struct Node *root = NULL;

    root = buildBinaryTree();

    if (hasDuplicateValues(root)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}




// Solution 2 

// #include <iostream>

// // Define the structure for a binary tree node
// struct Node {
//     int data;
//     Node* left;
//     Node* right;
// };

// // Function to count the number of nodes in the binary tree
// int nodeCount(Node* root) {
//     if (root == nullptr) {
//         return 0;
//     }
//     return 1 + nodeCount(root->left) + nodeCount(root->right);
// }

// // Function to create a new binary tree node
// Node* createNode(int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->left = newNode->right = nullptr;
//     return newNode;
// }

// // Function to build a binary tree from user input
// Node* buildBinaryTree() {
//     int data;
//     std::cin >> data;

//     if (data == -1) {
//         return nullptr; // Return nullptr for an empty node
//     }

//     Node* root = createNode(data);

//     root->left = buildBinaryTree();
//     root->right = buildBinaryTree();

//     return root;
// }

// // Function to check if a binary tree has duplicate values
// bool hasDuplicateValuesUtil(Node* root, int* prev_values, int* prev_index) {
//     if (root == nullptr) {
//         return false;
//     }

//     // Check if the current node's data matches any previous value.
//     for (int i = 0; i < *prev_index; i++) {
//         if (prev_values[i] == root->data) {
//             return true;
//         }
//     }

//     // Store the current node's data in the array of previous values.
//     prev_values[(*prev_index)++] = root->data;

//     // Recursively check for duplicate values in left and right subtrees.
//     return hasDuplicateValuesUtil(root->left, prev_values, prev_index) ||
//            hasDuplicateValuesUtil(root->right, prev_values, prev_index);
// }

// bool hasDuplicateValues(Node* root) {
//     int prev_index = 0;
//     int numNodes = nodeCount(root);

//     int* prev_values = new int[numNodes]; // Dynamically allocate memory

//     bool result = hasDuplicateValuesUtil(root, prev_values, &prev_index);

//     delete[] prev_values; // Free dynamically allocated memory

//     return result;
// }

// int main() {
//     Node* root = nullptr;

//     root = buildBinaryTree();

//     if (hasDuplicateValues(root)) {
//         std::cout << "Yes" << std::endl;
//     } else {
//         std::cout << "No" << std::endl;
//     }

//     return 0;
// }
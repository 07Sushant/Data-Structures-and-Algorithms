#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to the right child */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

int isBSTUtil(struct node* node, int min, int max);

/* Returns true if the given tree is a binary search tree
   (efficient version). */
int isBST(struct node* node) {
    return (isBSTUtil(node, INT_MIN, INT_MAX));
}

/* Returns true if the given tree is a BST and its
   values are >= min and <= max. */
int isBSTUtil(struct node* node, int min, int max) {
    /* An empty tree is BST */
    if (node == NULL)
        return 1;

    /* False if this node violates the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;

    /* Otherwise, check the subtrees recursively,
       tightening the min or max constraint */
    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data) {
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/* Function to build a binary tree from user input */
struct node* buildTree() {
    int data;
    struct node* root = NULL;

    scanf("%d", &data);

    if (data == -1)
        return NULL;

    root = newNode(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main() {
    struct node* root = buildTree();

    if (isBST(root))
        printf("The given binary tree is a BST\n");
    else
        printf("The given binary tree is not a BST\n");

    return 0;
}


//sol

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

   
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int isBSTUtil(Node* node, int min, int max);


int isBST(Node* node) {
    return (isBSTUtil(node, INT_MIN, INT_MAX));
}


int isBSTUtil(Node* node, int min, int max) {
    if (node == NULL)
        return 1;

    
    if (node->data < min || node->data > max)
        return 0;

   
    return isBSTUtil(node->left, min, node->data - 1)
        && // Allow only distinct values
        isBSTUtil(node->right, node->data + 1,
            max); // Allow only distinct values
}

Node* buildTree() {
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    Node* root = new Node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main() {
    Node* root = buildTree();

    if (isBST(root))
        cout << "The given binary tree is a BST" << endl;
    else
        cout << "The given binary tree is not a BST" << endl;

    return 0;
}


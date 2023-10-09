#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    } else {
        struct node* cur = (struct node*)malloc(sizeof(struct node));
        cur->data = data;
        cur->left = NULL;
        cur->right = NULL;
        
        if (root->left == NULL) {
            root->left = cur;
        } else if (root->right == NULL) {
            root->right = cur;
        } else {
            // If both left and right children are already present,
            // you can choose one side to insert the new node, e.g., left.
            root->left = insert(root->left, data);
        }
        
        return root;
    }
}

void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root = NULL;
    int n;
    int data;

    scanf("%d", &n);

    while (n-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    postOrder(root);
    return 0;
}
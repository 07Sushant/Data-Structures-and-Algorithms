#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void findPredecessor(Node* root, int val) {
    Node* predecessor = nullptr;
    while (root != nullptr) {
        if (val < root->data) {
            root = root->left;
        } else if (val > root->data) {
            predecessor = root;
            root = root->right;
        } else {
            if (root->left != nullptr) {
                Node* temp = root->left;
                while (temp->right != nullptr) {
                    temp = temp->right;
                }
                predecessor = temp;
            }
            break;
        }
    }
    if (predecessor != nullptr) {
        cout << "Inorder Predecessor: " << predecessor->data << endl;
    } else {
        cout << "Doesn't exist" << endl;
    }
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    int m;
    cin >> m;

    findPredecessor(root, m);

    return 0;
}

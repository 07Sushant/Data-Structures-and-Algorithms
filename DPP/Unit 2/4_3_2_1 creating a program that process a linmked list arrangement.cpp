#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* rearrangeList(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;

    Node* current = head;

    while (current) {
        if (current->data % 2 == 0) {  // Even number
            if (!evenHead) {
                evenHead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        } else {  // Odd number
            if (!oddHead) {
                oddHead = current;
                oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }
        current = current->next;
    }

    if (evenTail) {
        evenTail->next = oddHead;
    }

    if (oddTail) {
        oddTail->next = nullptr;
    }

    return evenHead ? evenHead : oddHead;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    Node* head = nullptr;

    for (int i = 0; i < n; ++i) {
        int data;
        std::cin >> data;
        Node* newNode = createNode(data);

        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    head = rearrangeList(head);

    printList(head);

    return 0;
}


//Sushant
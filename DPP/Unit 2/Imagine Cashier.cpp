// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int sumOfLastMNodes(Node* head, int m) {
    if (head == nullptr || m <= 0) {
        return 0;
    }

    Node* fast = head;
    Node* slow = head;
    int count = 0;
    int sum = 0;

    while (count < m && fast != nullptr) {
        fast = fast->next;
        count++;
    }

    if (count < m) {
        return 0;
    }

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    while (slow != nullptr) {
        sum += slow->data;
        slow = slow->next;
    }

    return sum;
}

int main() {
    int n, m;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cin >> m;

    int result = sumOfLastMNodes(head, m);
    cout << result << endl;

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


//Sushant
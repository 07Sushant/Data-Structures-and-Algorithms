#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char data;
    Node* next;

    Node(char val) : data(val), next(nullptr) {}
};

bool isPalindrome(vector<char>& chars) {
    int left = 0;
    int right = chars.size() - 1;

    while (left < right) {
        if (chars[left] != chars[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool isCircularListPalindrome(Node* head) {
    if (!head) {
        return false; }

    vector<char> chars;
    Node* current = head;
    do {
        chars.push_back(current->data);
        current = current->next;
    } while (current != head);

    return isPalindrome(chars);
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        char value;
        cin >> value;
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
            newNode->next = head; 
        } else {
            tail->next = newNode;
            tail = newNode;
            newNode->next = head; 
        }
    }

    if (isCircularListPalindrome(head)) {
        cout << "Linked list is a palindrome." << endl;
    } else {
        cout << "Linked list is not a palindrome." << endl;
    }

    if (head) {
        Node* current = head;
        do {
            Node* temp = current;
            current = current->next;
            delete temp;
        } while (current != head);
    }

    return 0;
}


#include <iostream>

struct Node {
    int data;
    Node* next;
};

class StudentRoster {
private:
    Node* head;

public:
    StudentRoster() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void rearrangeLinkedList() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* evenHead = nullptr;
        Node* evenTail = nullptr;
        Node* oddHead = nullptr;
        Node* oddTail = nullptr;
        Node* current = head;

        while (current != nullptr) {
            if (current->data % 2 == 0) {
                if (evenHead == nullptr) {
                    evenHead = current;
                    evenTail = current;
                } else {
                    evenTail->next = current;
                    evenTail = current;
                }
            } else {
                if (oddHead == nullptr) {
                    oddHead = current;
                    oddTail = current;
                } else {
                    oddTail->next = current;
                    oddTail = current;
                }
            }
            current = current->next;
        }

        if (evenTail != nullptr) {
            evenTail->next = oddHead;
        }

        if (oddTail != nullptr) {
            oddTail->next = nullptr;
        }

        head = evenHead;
    }

    void printRoster() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    StudentRoster roster;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        std::cin >> data;
        roster.insertAtBeginning(data);
    }

    roster.rearrangeLinkedList();
    roster.printRoster();

    return 0;
}
//sushant
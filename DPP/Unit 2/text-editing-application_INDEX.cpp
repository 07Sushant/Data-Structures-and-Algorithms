#include <iostream>

struct Node {
    char data;
    Node* next;
};

class GroundedHeaderLinkedList {
private:
    Node* header;
    int length;

public:
    GroundedHeaderLinkedList() {
        header = new Node();
        header->next = nullptr;
        length = 0;
    }

    void insertCharacter(int index, char character) {
        if (index < 0 || index > length) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = character;

        Node* current = header;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        ++length;
    }

    void displayList() {
        Node* current = header->next;
        std::cout << "Updated list: ";
        while (current != nullptr) {
            std::cout << current->data << ' ';
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;

    GroundedHeaderLinkedList linkedList;

    char character;
    for (int i = 0; i < n; ++i) {
        std::cin >> character;
        linkedList.insertCharacter(i, character);
    }

    int index;
    std::cin >> index;
    std::cin >> character;

    linkedList.insertCharacter(index, character);
    linkedList.displayList();

    return 0;
}

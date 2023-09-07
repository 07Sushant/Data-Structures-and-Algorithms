#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;

    Node(const string& data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void append(const string& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deleteAlternateNodes() {
        if (!head) {
            return;
        }

        Node* current = head;
        while (current && current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            current = current->next;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

private:
    Node* head;
};

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    if (n == 0) {
        cout << "List is empty" << endl;
        return 0;
    }

    string input;
    getline(cin, input);

    LinkedList linkedList;

    size_t start = 0;
    size_t end = input.find(" ");

    while (end != string::npos) {
        string element = input.substr(start, end - start);
        linkedList.append(element);
        start = end + 1;
        end = input.find(" ", start);
    }

    string lastElement = input.substr(start);
    linkedList.append(lastElement);

    cout << "Linked list data: ";
    linkedList.display();

    linkedList.deleteAlternateNodes();
    cout << "\nAfter deleting alternate node: ";
    linkedList.display();

    return 0;
}


//sUSAHNT
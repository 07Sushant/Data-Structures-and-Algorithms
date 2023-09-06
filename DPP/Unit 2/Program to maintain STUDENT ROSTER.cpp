#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next;

    Node(const string& _name) : name(_name), next(nullptr) {}
};

class StudentRoster {
private:
    Node* head;

public:
    StudentRoster() : head(nullptr) {}

    void insertNode(const string& newName, int position) {
        Node* newNode = new Node(newName);

        if (position == 1 || head == nullptr) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            int currentPosition = 1;

            while (currentPosition < position - 1 && current->next != nullptr) {
                current = current->next;
                currentPosition++;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void printRoster() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    StudentRoster roster;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        roster.insertNode(name, i + 1);
    }

    string newName;
    int position;
    cin >> newName >> position;

    cout << "Current Linked List:" << endl;
    roster.printRoster();

    roster.insertNode(newName, position);

    cout << "Updated Linked List:" << endl;
    roster.printRoster();

    return 0;
}



//Sushant
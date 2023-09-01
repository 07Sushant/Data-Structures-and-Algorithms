#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string value) {
        data = value;
        next = nullptr;
    }
};

class TextEditor {
private:
    Node* head;
    Node* tail;

public:
    TextEditor() {
        head = nullptr;
        tail = nullptr;
    }

    void insertLine(string line) {
        Node* newNode = new Node(line);
        newNode->next = head;
        head = newNode;
    }

    void appendLine(const string& data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current -> next != nullptr)
            {
                current = current ->next;
            }
            current -> next = newNode;
        }
    }

    void displayDocument() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            current = current->next;
            if (current != nullptr) {
                cout << " ";
            }
        }
        cout << " ";
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    TextEditor editor;

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        editor.insertLine(line);
    }

    string s;
    getline(cin, s);

    cout << "Document: ";
    editor.displayDocument();
    cout << endl;

    editor.appendLine(s);

    cout << "Updated Document: ";
    editor.displayDocument();
    cout << endl;

    return 0;
}

//sushant

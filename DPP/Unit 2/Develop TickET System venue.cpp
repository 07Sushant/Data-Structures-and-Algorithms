#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

typedef Node* NODE;

NODE getnode() {
    NODE x = new Node();
    return x;
}

NODE insertAtFront(NODE head, int item) {
    NODE temp = getnode();
    temp->data = item;

    if (head == nullptr) {
        head = temp;
        head->link = head;
    } else {
        temp->link = head->link;
        head->link = temp;
    }

    head->data++;
    return head;
}

NODE insertAtPosition(NODE head, int item, int position) {
    if (position < 1 || position > head->data + 1) {
        cout << "Invalid position." << endl;
        return head;
    }

    NODE temp = getnode();
    temp->data = item;

    if (head == nullptr) {
        head = temp;
        head->link = head;
        head->data++;
        return head;
    } else if (position == 1) {
        return insertAtFront(head, item);
    } else {
        NODE cur = head->link;
        for (int i = 1; i < position - 1; i++) {
            cur = cur->link;
        }

        temp->link = cur->link;
        cur->link = temp;
        head->data++;
    }

    return head;
}

NODE insertInMiddle(NODE head, int item) {
    int position = (head->data + 1) / 2; 

    return insertAtPosition(head, item, position);
}

void display(NODE head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "No of nodes in the CLL is " << head->data << endl;
    NODE temp = head->link;
    do {
        cout << "|" << temp->data << "| --> ";
        temp = temp->link;
    } while (temp != head);
    cout << endl;
}

int main() {
    NODE head = nullptr;
    int n;

    head = getnode();
    head->data = 0;
    head->link = head; 

    int value;

    cin >> n;

    if (n > 0) {
        for (int i = 0; i < n; i++) {
            cin >> value;
            head = insertAtFront(head, value);
        }

        cin >> value;
        head = insertInMiddle(head, value);

        cout << "After inserting at middle:" << endl;
        display(head);

        int position;
        cin >> position;
        if (position < 1 || position > head->data + 1) {
            cout << "Invalid position." << endl;
        } else {
            cin >> value;
            head = insertAtPosition(head, value, position);
            cout << "After inserting at position " << position << ":" << endl;
            display(head);
        }
    } else {
        cout << "List is empty." << endl;
    }

    return 0;
}
//sushants
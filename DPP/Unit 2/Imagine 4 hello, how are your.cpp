#include <iostream>
#include <string>

using namespace std;

struct Message {
    string content;
    Message* next;
};

Message* createMessageNode(const string& content) {
    Message* newMessage = new Message();
    newMessage->content = content;
    newMessage->next = nullptr;
    return newMessage;
}

Message* insertMessage(Message* head, const string& content) {
    Message* newMessage = createMessageNode(content);

    if (head == nullptr) {
        newMessage->next = newMessage;
    } else {
        newMessage->next = head->next;
        head->next = newMessage;
    }

    return newMessage;
}

Message* reverseInsertedMessages(Message* head) {
    if (head == nullptr || head->next == head) {
        return head;
    }

    Message* current = head;
    Message* prev = nullptr;
    Message* next = nullptr;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    head->next = prev;

    return head;
}

void displayMessages(Message* head) {
    if (head == nullptr) {
        cout << "Message queue is empty!" << endl;
        return;
    }

    Message* temp = head;
    cout << "Message Queue: " << endl;
    do {
        cout << "- " << temp->content << endl;
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Message* head = nullptr;
    int numMessages;

    cin >> numMessages;

    cin.ignore();

    for (int i = 0; i < numMessages; i++) {
        string content;
        getline(cin, content);
        head = insertMessage(head, content);
    }


    head = reverseInsertedMessages(head);
    displayMessages(head);

    return 0;
}


//Sushant
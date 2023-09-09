#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* prev, *next;
};

struct Node* getNode(int data)
{
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void sortedInsert(struct Node** head_ref, struct Node* newNode)
{
    struct Node* current;

    if (*head_ref == NULL)
        *head_ref = newNode;

    else if ((*head_ref)->data >= newNode->data) {
        newNode->next = *head_ref;
        newNode->next->prev = newNode;
        *head_ref = newNode;
    }

    else {
        current = *head_ref;

        while (current->next != NULL &&
            current->next->data < newNode->data)
            current = current->next;

        newNode->next = current->next;

        if (current->next != NULL)
            newNode->next->prev = newNode;

        current->next = newNode;
        newNode->prev = current;
    }
}

void printList(struct Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    struct Node* head = NULL;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;

        struct Node* new_node = getNode(data);
        sortedInsert(&head, new_node);
    }

    int lastData;
    cin >> lastData;
    struct Node* lastNode = getNode(lastData);
    sortedInsert(&head, lastNode);

    cout << "Created Doubly Linked List:\n";
    printList(head);

    return 0;
}


//Sushant
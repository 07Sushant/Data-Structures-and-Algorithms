#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    LinkedList() : head(nullptr) {}

    void append(int data)
    {
        Node *new_node = new Node(data);
        if (!head)
        {
            head = new_node;
        }
        else
        {
            Node *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    Node *reverseK(Node *head, int k)
    {
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        int count = 0;
        while (current && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        if (next && count >= k)
        {
            head->next = reverseK(next, k);
        }
        return prev;
    }

    void display()
    {
        Node *current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    int n, data, k;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> data;
        list.append(data);
    }
    cin >> k;
    cout << "Original Linked List: ";
    list.display();

    list.head = list.reverseK(list.head, k);

    cout << "Modified Linked List: ";
    list.display();
    return 0;
}


//Sushant
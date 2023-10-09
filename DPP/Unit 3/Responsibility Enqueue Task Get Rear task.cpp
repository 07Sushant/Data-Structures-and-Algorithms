#include <iostream>
#include <string>
using namespace std;

struct QNode {
    string data;
    QNode* next;
    QNode(const string& d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue {
    QNode *front, *rear;
    Queue() { front = rear = NULL; }

    void enQueue(const string& x)
    {
        // Create a new LL node
        QNode* temp = new QNode(x);

        // If queue is empty, then
        // new node is front and rear both
        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        // Add the new node at
        // the end of queue and change rear
        rear->next = temp;
        rear = temp;
    }
};

int main()
{
    Queue q;

    int num;
    cin >> num;
    cin.ignore(); // Ignore the newline character after reading the number

    for (int i = 0; i < num; i++) {
        string task;
        getline(cin, task);
        q.enQueue(task);
    }

    cout << "Front Task: " << ((q.front != NULL) ? (q.front)->data : "-1") << endl;
    cout << "Rear Task: " << ((q.rear != NULL) ? (q.rear)->data : "-1");

    return 0;
}
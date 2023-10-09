#include <iostream>

using namespace std;

struct Student {
    int id;
    int priority;
    Student* next;

    Student(int _id, int _priority) : id(_id), priority(_priority), next(nullptr) {}
};

class PriorityQueue {
private:
    Student* front;

public:
    PriorityQueue() : front(nullptr) {}

    void enqueue(int id, int priority) {
        Student* newStudent = new Student(id, priority);

        if (!front || priority < front->priority) {
            newStudent->next = front;
            front = newStudent;
        } else {
            Student* current = front;
            while (current->next && priority >= current->next->priority) {
                current = current->next;
            }
            newStudent->next = current->next;
            current->next = newStudent;
        }
    }

    void display() {
        Student* current = front;
        while (current) {
            cout << current->id << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    PriorityQueue pq;

    for (int i = 0; i < n; ++i) {
        int id, priority;
        cin >> id >> priority;
        pq.enqueue(id, priority);
    }

    cout << "Priority Queue: ";
    pq.display();

    return 0;
}

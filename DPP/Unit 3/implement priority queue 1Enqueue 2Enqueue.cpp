#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class PriorityQueue {
private:
    int arr[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return (size == MAX_SIZE);
    }

    void enqueue(int element, int priority) {
        if (isFull()) {
            cout << "Priority Queue is full. Unable to enqueue." << endl;
            return;
        }

        int i;
        for (i = size - 1; i >= 0; i--) {
            if (priorities[i] > priority) {
                arr[i + 1] = arr[i];
                priorities[i + 1] = priorities[i];
            } else {
                break;
            }
        }

        arr[i + 1] = element;
        priorities[i + 1] = priority;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue is empty. Unable to dequeue." << endl;
            return;
        }

        int frontPriority = priorities[0];
        int i = 1;
        while (i < size && priorities[i] == frontPriority) {
            i++;
        }

        for (int j = i; j < size; j++) {
            arr[j - i] = arr[j];
            priorities[j - i] = priorities[j];
        }

        size -= i;
    }

    void printPriorityQueue() {
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int element, priority;
        cin >> element;
        cin >> priority;
        pq.enqueue(element, priority);
    }

    pq.printPriorityQueue();

    pq.dequeue();

    pq.printPriorityQueue();

    return 0;
}
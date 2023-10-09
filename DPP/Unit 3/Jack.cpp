#include <iostream>
using namespace std;

void enqueue(int arr[], int& rear, int element) {
    arr[rear++] = element;
}

void dequeue(int arr[], int& front, int rear) {
    if (front == rear) {
        cout << "Queue underflow" << endl;
        return;
    }

    int maxIndex = front;
    for (int i = front + 1; i < rear; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    cout << arr[maxIndex] << " ";
    arr[maxIndex] = arr[front];
    front++;
}

void sortArray(int arr[], int size) {
    int front = 0, rear = 0;

    for (int i = 0; i < size; i+=2) {
        enqueue(arr, rear, arr[i]);
    }

    for (int i = 0; i < size; i+=2) {
        dequeue(arr, front, rear);
    }
}

int main() {
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Sorted elements in dequeue format: ";
    sortArray(arr, size);
    cout << endl;

    return 0;
}
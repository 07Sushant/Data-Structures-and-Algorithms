#include<iostream>
using namespace std;

// Declaration of the queue
int queue[50], n = 50, front = -1, rear = -1;

// Function to insert an element into the queue
void insertInqueue() {
    int value;
    // Check if the queue is full
    if (rear == n - 1) {
        cout << "Queue is full" << endl;
    }
    else {
        if (front == -1)
            front = 0;
        cout << "Insert the element in the queue: ";
        cin >> value;
        rear++;
        queue[rear] = value;
    }
}

// Function to delete an element from the queue
void deleteFromqueue() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Element deleted from the queue is: " << queue[front] << endl;
        front++;
        if (front > rear) {
            front = rear = -1; // Reset the queue when all elements are deleted
        }
    }
}

// Function to print all elements in the queue
void printqueue() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "The elements in the queue are: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "1) Insert element in the queue" << endl;
        cout << "2) Delete element from the queue" << endl;
        cout << "3) Print all elements in the queue" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertInqueue();
                break;
            case 2:
                deleteFromqueue();
                break;
            case 3:
                printqueue();
                break;
            case 4:
                cout << "Exiting the program" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
  if (top == MAX_SIZE - 1 || value >= MAX_SIZE) {
    cout << "Stack Overflow. Cannot push element." << endl;
    return;
  }

  stack[++top] = value;
  cout << "Element " << value << " pushed onto the stack." << endl;
}

void pop() {
  if (top == -1) {
    cout << "Stack Underflow. Cannot perform pop operation." << endl;
    return;
  }

  int element = stack[top--];
  cout << "Element " << element << " popped from the stack." << endl;
}

void displayStack() {
  if (top == -1) {
    cout << "Stack is empty." << endl;
    return;
  }

  cout << "Elements in the stack: ";
  for (int i = top; i >= 0; --i) {
    cout << stack[i] << " ";
  }
  cout << endl;
}

int main() {
  int choice, value;

  do {
    std::cin >> choice;

    switch (choice) {
      case 1:
        cin >> value;
        push(value);
        break;
      case 2:
        pop();
        break;
      case 3:
        displayStack();
        break;
      case 4:
        cout << "Exiting the program." << endl;
        break;
      default:
        cout << "Invalid choice." << endl;
    }
  } while (choice != 4);

  return 0;
}

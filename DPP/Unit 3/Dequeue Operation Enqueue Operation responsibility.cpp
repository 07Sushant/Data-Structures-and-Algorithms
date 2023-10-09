#include <iostream>
using namespace std;

int front = 0, rear = 0;

int main() {
  int max_size;
  cin >> max_size;

  int* queue = new int[max_size]; 

  int value;
  for (int i = 0; i < max_size; i++) {
    cin >> value;
    if (rear < max_size) {
      queue[rear++] = value;
    } else {
      break;
    }
  }

  cout << "Dequeuing elements: ";
  while (front < rear) {
    cout << queue[front++] << " ";
  }
  cout << endl;

  delete[] queue; 

  return 0;
}
#include <iostream>
using namespace std;

void reverseDeque(int* dq, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int temp = dq[left];
        dq[left] = dq[right];
        dq[right] = temp;
        left++;
        right--;
    }
}

int main() {
    int n;
    cin >> n;

    int* myDeque = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> myDeque[i];
    }

    reverseDeque(myDeque, n);

    for (int i = 0; i < n; i++) {
        cout << myDeque[i] << " ";
    }
    // cout << endl;

    delete[] myDeque;

    return 0;
}
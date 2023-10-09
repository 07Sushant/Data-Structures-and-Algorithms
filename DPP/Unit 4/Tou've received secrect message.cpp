#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array for Quick Sort
int partition(vector<char>& arr, int low, int high) {
    char pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform Quick Sort on characters in ascending order
void quickSort(vector<char>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> characters(n);

    for (int i = 0; i < n; i++) {
        cin >> characters[i];
    }

    quickSort(characters, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << characters[i] << " ";
    }

    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to partition the array of words for Quick Sort
int partition(vector<string>& arr, int low, int high) {
    string pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform Quick Sort on words in reverse lexicographical order
void quickSort(vector<string>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline character

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    quickSort(words, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << words[i] << " ";
    }

    cout << endl;

    return 0;
}

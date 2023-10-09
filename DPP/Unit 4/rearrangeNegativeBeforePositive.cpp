#include <iostream>
#include <vector>

using namespace std;

// Function to rearrange the elements so that negative numbers appear before positive numbers
void rearrangeNegativesBeforePositives(int arr[], int n) {
    int i = 0;
    int j = n - 1;

    while (i <= j) {
        if (arr[i] < 0 && arr[j] >= 0) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        } else if (arr[i] >= 0) {
            i++;
        } else {
            j--;
        }
    }
}

// Function to partition the array for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform Quick Sort on the rearranged array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    rearrangeNegativesBeforePositives(arr, n);
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}

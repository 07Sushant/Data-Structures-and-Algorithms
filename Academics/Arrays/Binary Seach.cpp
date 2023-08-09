#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (arr[mid] == target) {
            return mid; 
        }
        else if (arr[mid] < target) {
            left = mid + 1; 
        }
        else {
            right = mid - 1; 
        }
    }

    return -1; 
}

int main() {
    int x;
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Enter the searching value: "<< endl;
    cin >> x;
    int target = x;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        cout << "Target found at index " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }

    return 0;
}

//Sushant
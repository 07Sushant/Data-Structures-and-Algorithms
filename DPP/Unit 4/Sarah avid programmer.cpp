#include <iostream>
using namespace std;

void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left_size) {
        arr[k++] = left[i++];
    }

    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

void mergeSortOdd(int arr[], int n) {
    if (n > 1) {
        int mid = n / 2;
        int left[mid];
        int right[n - mid];

        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }
        for (int i = mid; i < n; i++) {
            right[i - mid] = arr[i];
        }

        mergeSortOdd(left, mid);
        mergeSortOdd(right, n - mid);

        merge(arr, left, mid, right, n - mid);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int oddCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount == 0) {
        cout << "None";
    } else {
        mergeSortOdd(arr, n);
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}










//Sol2



// #include <stdio.h>

// void merge(int arr[], int left[], int left_size, int right[], int right_size) {
//     int i = 0, j = 0, k = 0;

//     while (i < left_size && j < right_size) {
//         if (left[i] < right[j]) {
//             arr[k++] = left[i++];
//         } else {
//             arr[k++] = right[j++];
//         }
//     }

//     while (i < left_size) {
//         arr[k++] = left[i++];
//     }

//     while (j < right_size) {
//         arr[k++] = right[j++];
//     }
// }

// void mergeSortOdd(int arr[], int n) {
//     if (n > 1) {
//         int mid = n / 2;
//         int left[mid];
//         int right[n - mid];

//         for (int i = 0; i < mid; i++) {
//             left[i] = arr[i];
//         }
//         for (int i = mid; i < n; i++) {
//             right[i - mid] = arr[i];
//         }

//         mergeSortOdd(left, mid);
//         mergeSortOdd(right, n - mid);

//         merge(arr, left, mid, right, n - mid);
//     }
// }

// int main() {
//     int n;
//     scanf("%d", &n);

    
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     int oddCount = 0;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] % 2 != 0) {
//             oddCount++;
//         }
//     }

//     if (oddCount == 0) {
//         printf("None");
//     } else {
//         mergeSortOdd(arr, n);
//         for (int i = 0; i < n; i++) {
//             if (arr[i] % 2 != 0) {
//                 printf("%d ", arr[i]);
//             }
//         }
//         printf("\n");
//     }

//     return 0;
// }
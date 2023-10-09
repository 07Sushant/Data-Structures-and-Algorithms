
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isValidInorder(int arr[], int n) {
    int minVal = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] < minVal) {
            return false;
        }
        minVal = arr[i];
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (isValidInorder(arr, n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
#include <stdio.h>

int findMinimum(int array[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (array[mid] > array[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return array[left];
}

int main() {
    int n;
    scanf("%d", &n);
    int array[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int minimum = findMinimum(array, n);
    printf("%d\n", minimum);

    return 0;
}

#include <stdio.h>

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        printf("After Iteration %d:", i);
        for (int k = 0; k < n; k++) {
            printf(" %.2f", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    float prices[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &prices[i]);
    }

    printf("Initial order:");
    for (int i = 0; i < n; i++) {
        printf(" %.2f", prices[i]);
    }
    printf("\n");

    insertionSort(prices, n);

    printf("Sorted order:");
    for (int i = 0; i < n; i++) {
        printf(" %.2f", prices[i]);
    }
    printf("\n");

    return 0;
}

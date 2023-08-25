#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int heights[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    selectionSort(heights, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf(" %d", heights[i]);
    }
    printf("\n");

    printf("The second largest element is %d\n", heights[1]);

    return 0;
}

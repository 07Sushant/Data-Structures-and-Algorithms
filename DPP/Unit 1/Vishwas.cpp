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
        
        printf("After his step: %d\n", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
    printf("Finally, he got it\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int films[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &films[i]);
    }

    selectionSort(films, n);

    return 0;
}

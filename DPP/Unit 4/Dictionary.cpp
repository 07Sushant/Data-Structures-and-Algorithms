
#include <stdio.h>
#include <string.h>

#define MAX_Char_LENGTH 30

void merge(char arr[][MAX_Char_LENGTH], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char L[n1][MAX_Char_LENGTH], R[n2][MAX_Char_LENGTH];

    for (int i = 0; i < n1; i++) {
        strcpy(L[i], arr[left + i]);
    }
    for (int i = 0; i < n2; i++) {
        strcpy(R[i], arr[mid + 1 + i]);
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}

void mergeSort(char arr[][MAX_Char_LENGTH], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int size;
    scanf("%d", &size);
    char arr[size][MAX_Char_LENGTH];

    for (int i = 0; i < size; i++) {
        scanf("%s", arr[i]);
    }
    
    mergeSort(arr, 0, size - 1);

    printf("Sorted Characters: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    return 0;
}
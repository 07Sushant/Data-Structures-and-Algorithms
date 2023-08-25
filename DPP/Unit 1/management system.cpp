#include <stdio.h>
#include <string.h>

void insertionSort(char contacts[][50], int n) {
    for (int i = 1; i < n; i++) {
        char key[50];
        strcpy(key, contacts[i]);
        int j = i - 1;

        while (j >= 0 && strcmp(contacts[j], key) > 0) {
            strcpy(contacts[j + 1], contacts[j]);
            j--;
        }

        strcpy(contacts[j + 1], key);

        printf("After Iteration %d:", i);
        for (int k = 0; k < n; k++) {
            printf(" %s", contacts[k]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char contacts[n][50];

    for (int i = 0; i < n; i++) {
        scanf("%s", contacts[i]);
    }

    printf("Initial order:");
    for (int i = 0; i < n; i++) {
        printf(" %s", contacts[i]);
    }
    printf("\n");

    insertionSort(contacts, n);

    printf("Sorted order:");
    for (int i = 0; i < n; i++) {
        printf(" %s", contacts[i]);
    }
    printf("\n");

    return 0;
}

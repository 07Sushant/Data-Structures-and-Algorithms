#include <stdio.h>

void main() {
    int array[100];
    int i, n, x, pos;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Input array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\nEnter the new element to be inserted: ");
    scanf("%d", &x);
    printf("Enter the position where you want to insert the element: ");
    scanf("%d", &pos);

    
    for (i = n; i >= pos; i--) {
        array[i] = array[i - 1];
    }

    array[pos - 1] = x;
    n = n + 1;

    printf("New array after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}


//Sushant
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int array[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    int target;
    scanf("%d", &target);

    int found = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] == target) {
                printf("[%d][%d]\n", i, j);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Element %d not found.\n", target);
    }

    return 0;
}
//Sushant

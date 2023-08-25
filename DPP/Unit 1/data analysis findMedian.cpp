#include <stdio.h>

int countLessThanOrEqualToMid(int matrix[], int rows, int cols, int mid) {
    int count = 0;
    int row = rows - 1;
    int col = 0;

    while (row >= 0 && col < cols) {
        if (matrix[row * cols + col] <= mid) {
            count += (row + 1);
            col++;
        } else {
            row--;
        }
    }

    return count;
}

int findMedian(int matrix[], int rows, int cols) {
    int low = matrix[0];
    int high = matrix[rows * cols - 1];
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = countLessThanOrEqualToMid(matrix, rows, cols, mid);

        if (count <= (rows * cols) / 2) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int matrix[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int median = findMedian((int *)matrix, m, n);
    printf("%d\n", median);

    return 0;
}
//07Sushant

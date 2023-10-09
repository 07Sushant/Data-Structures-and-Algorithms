#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapStrings(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void swapInts(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char *names[], int heights[], int low, int high) {
    int pivot = heights[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (heights[j] >= pivot) {
            i++;
            swapStrings(&names[i], &names[j]);
            swapInts(&heights[i], &heights[j]);
        }
    }
    swapStrings(&names[i + 1], &names[high]);
    swapInts(&heights[i + 1], &heights[high]);
    return i + 1;
}

void quickSort(char *names[], int heights[], int low, int high) {
    if (low < high) {
        int pivot = partition(names, heights, low, high);
        quickSort(names, heights, low, pivot - 1);
        quickSort(names, heights, pivot + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char **names = (char **)malloc(n * sizeof(char *));
    int *heights = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        names[i] = (char *)malloc(100 * sizeof(char)); // Assuming max name length is 100
        scanf("%s %d", names[i], &heights[i]);
    }

    quickSort(names, heights, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s ", names[i]);
        free(names[i]);
    }

    free(names);
    free(heights);
    return 0;
}



//Solution 2


#include <iostream>
#include <string>

using namespace std;

int partition(string names[], int heights[], int low, int high) {
    int pivot = heights[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (heights[j] >= pivot) { // Sort in descending order based on heights
            i++;
            swap(names[i], names[j]);
            swap(heights[i], heights[j]);
        }
    }
    swap(names[i + 1], names[high]);
    swap(heights[i + 1], heights[high]);
    return i + 1;
}

void quickSort(string names[], int heights[], int low, int high) {
    if (low < high) {
        int pivot = partition(names, heights, low, high);
        quickSort(names, heights, low, pivot - 1);
        quickSort(names, heights, pivot + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    string *names = new string[n];
    int *heights = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> names[i] >> heights[i];
    }

    quickSort(names, heights, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << names[i] << " ";
    }

    delete[] names;
    delete[] heights;
    return 0;
}



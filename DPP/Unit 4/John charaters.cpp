#include <iostream>
using namespace std;

const int MAX_N = 15;

int isConsonant(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' &&
            ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U') {
            return 1;
        }
    }
    return 0;
}

void merge(char characters[], int left, int middle, int right, int consonant_count[]) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    char leftArr[n1];
    char rightArr[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = characters[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = characters[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (isConsonant(leftArr[i]) > isConsonant(rightArr[j])) {
            characters[k] = rightArr[j];
            j++;
        } else {
            characters[k] = leftArr[i];
            if (!isConsonant(leftArr[i])) {
                consonant_count[k] = 0;
            }
            i++;
        }
        k++;
    }

    while (i < n1) {
        characters[k] = leftArr[i];
        if (!isConsonant(leftArr[i])) {
            consonant_count[k] = 0;
        }
        i++;
        k++;
    }

    while (j < n2) {
        characters[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(char characters[], int left, int right, int consonant_count[]) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(characters, left, middle, consonant_count);
        mergeSort(characters, middle + 1, right, consonant_count);

        merge(characters, left, middle, right, consonant_count);
    }
}

int main() {
    int n;
    cin >> n;

    char characters[MAX_N];
    int consonant_count[MAX_N] = {1};

    for (int i = 0; i < n; i++) {
        cin >> characters[i];
    }

    mergeSort(characters, 0, n - 1, consonant_count);

    for (int i = 0; i < n; i++) {
        cout << characters[i] << " ";
    }

    cout << endl;

    return 0;
}

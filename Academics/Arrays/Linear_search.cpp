#include <iostream>
using namespace std;
int linearSearch(int array[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i; 
        }
    }
    return -1; 
}

int main() {

    int x;

    int array[] = {12, 45, 67, 23, 89, 34, 56};
    int arraySize = sizeof(array) / sizeof(array[0]); 

    cout<<"searching value: "<<endl;
    cin >>x;
    int searchValue = x; 

    int result = linearSearch(array, arraySize, searchValue);

    if (result != -1) {
        std::cout << "Value " << searchValue << " found at index " << result << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found" << std::endl;
    }

    return 0;
}
//sushant
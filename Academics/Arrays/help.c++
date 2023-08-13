#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int array[size];
    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    unordered_map<int, int> frequencyMap;
    for (int i = 0; i < size; i++) {
        if (frequencyMap.find(array[i]) != frequencyMap.end()) {
            frequencyMap[array[i]]++;
        } else {
            frequencyMap[array[i]] = 1;
        }
    }

    cout << "Element : Frequency" << endl;
    for (auto it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}

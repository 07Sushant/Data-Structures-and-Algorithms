#include <iostream>
using namespace std;
const int MAX_N = 20; 

int maximumLoot(int hval[], int n) {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return hval[0];
    } else {
        int robCurrentHouse = hval[n] + maximumLoot(hval, n - 2);
        int skipCurrentHouse = maximumLoot(hval, n - 1);
        return max(robCurrentHouse, skipCurrentHouse);
    }
}

int main() {
    int n;
    cin >> n;
    int hval[MAX_N];
    for (int i = 0; i < n; i++) {
        cin >> hval[i];
    }
    cout << maximumLoot(hval, n - 1); 
    return 0;
}


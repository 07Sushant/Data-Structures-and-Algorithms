#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n;

    std::vector<int> arr1(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr1[i];
    }

    std::cin >> m;

    std::vector<int> arr2(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> arr2[i];
    }

    std::vector<int> mergedArray;
    mergedArray.reserve(n + m);
    mergedArray.insert(mergedArray.end(), arr1.begin(), arr1.end());
    mergedArray.insert(mergedArray.end(), arr2.begin(), arr2.end());

    int minIngredient = *std::min_element(mergedArray.begin(), mergedArray.end());

    std::cout << minIngredient << std::endl;

    return 0;
}

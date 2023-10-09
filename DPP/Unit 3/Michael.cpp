#include <iostream>
#include <deque>

int main() {
    std::deque<int> stockPrices;

    int price;
    while (true) {
        std::cin >> price;
        if (price == -1) {
            break;
        }
        stockPrices.push_back(price);
    }

    if (stockPrices.empty()) {
        std::cout << "No stock prices provided." << std::endl;
    } else {
        int minPrice = stockPrices.front();
        for (int price : stockPrices) {
            if (price < minPrice) {
                minPrice = price;
            }
        }
        std::cout << "The minimum element in the deque is: " << minPrice << std::endl;
    }

    return 0;
}


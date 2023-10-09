#include <iostream>
#include <deque>
#include <unordered_set>
#include <vector>

int main() {
    std::deque<int> userIds;
    std::unordered_set<int> uniqueUserIds;
    std::vector<int> uniqueUserIdsVector;

    int userId;
    while (true) {
        std::cin >> userId;
        if (userId == -1) {
            break;
        }
        userIds.push_back(userId);
        if (uniqueUserIds.insert(userId).second) {
            // If it's a new unique user ID, add it to the vector
            uniqueUserIdsVector.push_back(userId);
        }
    }

    if (userIds.empty()) {
        std::cout << "" << std::endl;
    } else {
        std::cout << "";
        for (int userId : uniqueUserIdsVector) {
            std::cout << " " << userId;
        }
        std::cout << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <queue>

struct Package {
    std::string destination;
    int priority;

    Package(const std::string& dest, int prio) : destination(dest), priority(prio) {}

    bool operator<(const Package& other) const {
        return priority > other.priority;
    }
};

int main() {
    std::priority_queue<Package> deliveryQueue;

    int choice;
    do {
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string destination;
                int priority;
                std::cin.ignore();
                std::getline(std::cin, destination);
                std::cin >> priority;
                if (priority < 1) priority = 1;
                if (priority > 5) priority = 5;
                deliveryQueue.push(Package(destination, priority));
                std::cout << "Package added to the delivery queue.\n";
                break;
            }
            case 2:
                if (!deliveryQueue.empty()) {
                    std::cout << "Delivered package to: " << deliveryQueue.top().destination << "\n";
                    deliveryQueue.pop();
                } else {
                    std::cout << "No packages in the delivery queue.\n";
                }
                break;
            case 3:
                if (!deliveryQueue.empty()) {
                    std::cout << "Next package for delivery: " << deliveryQueue.top().destination << "\n";
                } else {
                    std::cout << "No packages in the delivery queue.\n";
                }
                break;
            case 4:
                std::cout << "Exiting the application.\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}


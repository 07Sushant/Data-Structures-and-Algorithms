#include <iostream>
#include <deque>
#include <string>

int main() {
    std::deque<std::string> waitlist;

    while (true) {
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string customerName;
            std::cin >> customerName;
            waitlist.push_back(customerName);
            std::cout << customerName << " has been added to the waitlist." << std::endl;
        } else if (choice == 2) {
            if (!waitlist.empty()) {
                std::cout << waitlist.front() << " has been removed from the waitlist." << std::endl;
                waitlist.pop_front();
            } else {
                std::cout << "Error: Waitlist is empty" << std::endl;
            }
        } else if (choice == 3) {
            if (!waitlist.empty()) {
                std::string customerName = waitlist.front();
                waitlist.pop_front();
                waitlist.push_back(customerName);
                std::cout << customerName << " has been moved to the back of the waitlist." << std::endl;
            } else {
                std::cout << "Error: Waitlist is empty" << std::endl;
            }
        } else if (choice == 4) {
            if (!waitlist.empty()) {
                std::cout << "Current waitlist:" << std::endl;
                for (const std::string& customer : waitlist) {
                    std::cout << customer << std::endl;
                }
            } else {
                std::cout << "Empty" << std::endl;
            }
        } else if (choice == 5) {
            std::cout << "Exiting" << std::endl;
            break;
        } else {
            std::cout << "Invalid option!" << std::endl;
        }
    }

    return 0;
}

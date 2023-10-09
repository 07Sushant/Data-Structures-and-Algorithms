#include <iostream>
#include <deque>

int main() {
    int n;
    std::cin >> n;
    std::deque<int> dq;

    for (int i = 0; i < n; i++) {
        int element;
        std::cin >> element;
        dq.push_front(element);
    }

    int num_deletions;
    std::cin >> num_deletions;


    num_deletions = std::min(num_deletions, static_cast<int>(dq.size()));

    if (dq.empty()) {
        std::cout << "The front element is -1." << std::endl;
    } else {
        std::cout << "The front element is " << dq.front() << "." << std::endl;
    }

    while (num_deletions > 0 && !dq.empty()) {
        dq.pop_front();
        num_deletions--;
    }

    if (dq.empty()) {
        std::cout << "After deletion, the front element becomes -1." << std::endl;
    } else {
        std::cout << "After deletion, the front element becomes " << dq.front() << "." << std::endl;
    }

    return 0;
}

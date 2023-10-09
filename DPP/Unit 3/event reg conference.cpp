#include <iostream>
#include <vector>

class EventRegistrationQueue {
private:
    std::vector<int> queue;

public:
    void enqueue(int registration_id) {
        if (registration_id % 2 == 0) {
            queue.push_back(registration_id);
        } else {
            std::cout << "Invalid element " << registration_id << ", only even numbers can be enqueued" << std::endl;
        }
    }

    int dequeue() {
        if (!queue.empty()) {
            int front = queue.front();
            queue.erase(queue.begin());
            return front;
        }
        return -1; // Return -1 for an empty queue, but you can choose another suitable value.
    }

    bool isEmpty() const {
        return queue.empty();
    }
};

int main() {
    int n;
    std::cin >> n;
    EventRegistrationQueue eventQueue;

    for (int i = 0; i < n; ++i) {
        int registration_id;
        std::cin >> registration_id;
        eventQueue.enqueue(registration_id);
    }

    std::vector<int> even_registration_ids;
    while (!eventQueue.isEmpty()) {
        int registration_id = eventQueue.dequeue();
        if (registration_id != -1) {
            even_registration_ids.push_back(registration_id);
        }
    }

    for (int id : even_registration_ids) {
        std::cout << id << " ";
    }

    return 0;
}

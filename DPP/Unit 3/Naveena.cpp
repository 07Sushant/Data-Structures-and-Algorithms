#include <iostream>
#include <algorithm>

struct Packet {
    int priority;
    std::string data;
};

struct PacketComparator {
    bool operator()(const Packet& p1, const Packet& p2) {
        // Higher priority packets have lower priority values
        return p1.priority > p2.priority;
    }
};

struct PriorityQueue {
    Packet* packets;
    int capacity;
    int size;

    PriorityQueue(int maxCapacity) {
        capacity = maxCapacity;
        packets = new Packet[capacity];
        size = 0;
    }

    void push(const Packet& packet) {
        if (size >= capacity) {
            std::cerr << "Queue is full" << std::endl;
            return;
        }

        packets[size++] = packet;
        std::push_heap(packets, packets + size, PacketComparator());
    }

    Packet pop() {
        if (size <= 0) {
            std::cerr << "Queue is empty" << std::endl;
            return Packet();
        }

        std::pop_heap(packets, packets + size, PacketComparator());
        return packets[--size];
    }

    ~PriorityQueue() {
        delete[] packets;
    }
};

int main() {
    int maxCapacity;
    std::cin >> maxCapacity;

    PriorityQueue priorityQueue(maxCapacity);

    int numPackets;
    std::cin >> numPackets;

    std::cin.ignore(); // Ignore the newline character after reading numPackets

    for (int i = 0; i < numPackets; i++) {
        Packet packet;
        std::cin >> packet.priority;
        std::cin.ignore(); // Ignore the newline character
        std::getline(std::cin, packet.data);

        priorityQueue.push(packet);
    }

    std::cout << "Processing packets based on priority:" << std::endl;
    while (priorityQueue.size > 0) {
        Packet packet = priorityQueue.pop();
        std::cout << "Processing packet with priority " << packet.priority << " and data: " << packet.data << std::endl;
    }

    return 0;
}

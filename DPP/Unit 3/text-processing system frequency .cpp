#include <iostream>
#include <string>

const int MAX_SIZE = 100;

struct Queue {
    int queue[MAX_SIZE];
    int front;
    int rear;
};

void initializeQueue(Queue& q) {
    q.front = -1;
    q.rear = -1;
}

bool isEmpty(const Queue& q) {
    return q.front == -1;
}

bool isFull(const Queue& q) {
    return q.rear == MAX_SIZE - 1;
}

void enqueue(Queue& q, int data) {
    if (isFull(q)) {
        return;
    }

    if (isEmpty(q)) {
        q.front = 0;
    }

    q.rear++;
    q.queue[q.rear] = data;
}

int dequeue(Queue& q) {
    if (isEmpty(q)) {
        return -1; // Assuming -1 as an invalid value for the dequeue operation
    }

    int data = q.queue[q.front];

    if (q.front == q.rear) {
        initializeQueue(q);
    } else {
        q.front++;
    }

    return data;
}

struct Solution {
    int firstUniqChar(const std::string& s) {
        Queue q;
        initializeQueue(q);
        int arr[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            enqueue(q, i);
            arr[ch - 'a']++;

            while (!isEmpty(q)) {
                if (arr[s[q.queue[q.front]] - 'a'] > 1) {
                    dequeue(q);
                } else {
                    break;
                }
            }
        }

        if (isEmpty(q))
            return -1;
        return q.queue[q.front];
    }
};

int main() {
    Solution solution;
    std::string input;
    std::cin >> input;

    int result = solution.firstUniqChar(input);
    std::cout << result ;

    return 0;
}
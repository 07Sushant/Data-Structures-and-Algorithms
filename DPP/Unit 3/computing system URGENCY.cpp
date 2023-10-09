#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    int priority;
    int deadline;
    string taskName;

    bool operator<(const Task& other) const {
        if (priority != other.priority) {
            return priority > other.priority; 
        } else {
            return deadline < other.deadline; 
        }
    }
};

int main() {
    int N;
    cin >> N;
    vector<Task> tasks(N);
    for (int i = 0; i < N; i++) {
        cin >> tasks[i].priority >> tasks[i].deadline >> tasks[i].taskName;
    }

    sort(tasks.begin(), tasks.end());

    cout << "Executed Tasks:" << endl;
    for (const auto& task : tasks) {
        cout << task.taskName << endl;
    }
    return 0;
}


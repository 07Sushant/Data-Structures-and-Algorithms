#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<queue<int>> queues(k);

    for (int i = 0; i < n; i++) {
        int item, qn;
        cin >> item >> qn;
        queues[qn].push(item);
    }

    for (int i = 0; i < k; i++) {
        cout << "Queue " << i << ": ";
        while (!queues[i].empty()) {
            cout << queues[i].front() << " ";
            queues[i].pop();
        }
        cout << endl;
    }

    return 0;
}

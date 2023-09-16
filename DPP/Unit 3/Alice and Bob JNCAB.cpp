#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    stack<char> charStack;
    
    for (char c : s) {
        charStack.push(c);
    }
    
    while (!charStack.empty()) {
        cout << charStack.top();
        charStack.pop();
    }
    
    cout << endl;
    
    return 0;
}

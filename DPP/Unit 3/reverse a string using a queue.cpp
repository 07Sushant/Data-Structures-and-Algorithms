#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reverseString(const string& input) {
    stack<char> charStack;
    for (char ch : input) {
        charStack.push(ch);
    }

    string reversed;
    while (!charStack.empty()) {
        reversed += charStack.top();
        charStack.pop();
    }

    return reversed;
}

int main() {
    string input;
    getline(cin, input);

    string reversed = reverseString(input);

    cout << "Reversed string: " << reversed << endl;

    return 0;
}

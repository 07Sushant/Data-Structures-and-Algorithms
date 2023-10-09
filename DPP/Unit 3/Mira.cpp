
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> mystack;

    while (true)
    {
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cin >> value;
            mystack.push(value);
            break;
        }
        case 2:
        {
            if (mystack.empty())
            {
                cout << "Stack is empty. Cannot perform pop operation." << endl;
            }
            else
            {
                mystack.pop();
            }
            break;
        }
        case 3:
        {
            if (mystack.empty())
            {
                cout << "Stack is empty." << endl;
            }
            else
            {
                cout << "Elements in the stack:";
                stack<int> tempStack = mystack;
                while (!tempStack.empty())
                {
                    cout << " " << tempStack.top();
                    tempStack.pop();
                }
                cout << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Exiting the program." << endl;
            return 0;
        }
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}

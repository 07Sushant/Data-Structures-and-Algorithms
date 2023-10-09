#include <iostream>
using namespace std;

void printNGE(int arr[], int n)
{
    int nextGreater[n];

    for (int i = 0; i < n; i++)
    {
        nextGreater[i] = -1;
    }

    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        int next = arr[i];

       
        while (top >= 0 && arr[stack[top]] < next)
        {
            nextGreater[stack[top]] = next;
            top--;
        }

        stack[++top] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " << ((nextGreater[i] != -1) ? nextGreater[i] : -1) << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printNGE(arr, n);
    return 0;
}

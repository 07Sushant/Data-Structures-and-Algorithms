#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int A[n];

    for(int i =0; i<=n; ++i)
    {
        cout <<"Enetr element: "<<i<<": ";
        cin >> A[i];

    }

    cout<<"Array element: ";
    for (int i = 0; i < n; ++i)
    {
        cout << A[i] << " ";

    }
    return 0;
}

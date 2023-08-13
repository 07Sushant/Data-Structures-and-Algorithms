#include <iostream>
using namespace std;
main()
{
    int n;
    cout<<"Enter the size the array:";
    cin >>n;

    int A[n];

    for (int i = 0; i<n; ++i)
    {
        cout << "Enter element: "<<i<<": "<<endl;
        cin >> A[i];
        
    }

    cout <<"Array element: ";
    for(int i = 0; i<n; ++i)
    {
        cout << A[i] << " ";
    }


    return 0;

    
}


#include<iostream>
using namespace std;

void merge(int *arr, int start, int end){
    int mid=(start+end)/2;
    int len1=mid-start+1;
    int len2 = end-mid;


    int *first = new int[len1];
    int *second =  new int [len2];

    // copy the ememnet from main to sub array 

        for (int i = 0; i < len1; i++){
        first[i] = arr[start + i];}
        for (int i = 0; i < len2; i++){
        second[i] = arr[mid + 1 + i];}

        





}

void mergesort(int *arr, int start, int end)
{
    if (start>=end)
    {
        return;  // if one lelement is there 

    }

    int mid = (start + end) / 2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);

    //merger the sorted sub array 


    merge(arr, start, end);

}


int main()
{
    int n;
    cout<<"Enter the no of element for array:";
    cout <<"Enter"<<n<<"Elements: ";

    for (int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
}


mergesort(arr, 0, n-1);
cout<<"Sorted Array:";
for (int i = 0; i<n; i++)
{
    cout<<arr[i];
}





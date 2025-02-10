/*Define a recursive function that takes an array as input.
Swap the first and last elements.
Recursively call the function with the remaining subarray.*/
#include <iostream>
using namespace std;

void reverse_arr(int arr[],int start,int end)
{
    if(start>=end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    
     reverse_arr(arr,start+1,end-1);
}

void print_arr(int arr[],int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<'\t';
}

int main()
{
    int arr[100],n,i;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array element: ";
    for(i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Before reversing the array elements are: ";
    print_arr(arr,n);

    reverse_arr(arr,0,n-1);
    cout<<"\nAfter reversing the array elements are: ";
    print_arr(arr,n);
    
}
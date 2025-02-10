/*Iterate through the array using two pointers (start and end).
Swap elements at the start and end pointers.
Move the start pointer towards the end and the end pointer towards the start until they meet or cross each other.*/
#include <iostream>
using namespace std;

void reverse_arr(int arr[],int start,int end)
{
    while(start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
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
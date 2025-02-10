//Create a new array of the same size as the original array.
//Copy elements from the original array to the new array in reverse order.
#include <iostream>
using namespace std;

void reverse_arr(int arr[],int size)
{
    int copy_arr[size];
    for(int i=0;i<size;i++)
        copy_arr[i] = arr[size-i-1];


    //printing
    cout<<"Reversing the array: ";
    for(int i=0 ;i<size;i++)
        cout<<copy_arr[i]<<'\t';
}




int main()
{
    int arr[100],n,i;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array element: ";
    for(i=0;i<n;i++)
        cin>>arr[i];

    reverse_arr(arr,n);
    
}
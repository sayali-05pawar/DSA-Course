//Find max from single array elements
#include <iostream>
using namespace std;

int findmax(int arr[100],int size)
{
	int max,i;
	max=arr[0];
	for(i=0;i<size;i++)
		if(max<arr[i])
			max=arr[i];
	
	return max;	
}

int main()
{
	int arr[100],sz,i,x;
	cout<<"Enter the size of array: ";
	cin>>sz;
	cout<<"Enter the array elements: ";
	for(i=0;i<sz;i++)
		cin>>arr[i];
		
	x = findmax(arr,sz);
	
	cout<<"Maximum element in the given array is: "<<x;
	return 0;
}

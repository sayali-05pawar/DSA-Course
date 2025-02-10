//Deleting an element in given array at given position
#include <iostream>
using namespace std;

int main()
{
	int arr[100],n,delpos,i;
	cout<<"Enter the size: ";
	cin>>n;
	
	cout<<"Enter the array elements: ";
	for(i=0;i<n;i++)
		cin>>arr[i];
		
	//Deleting Logic
	cout<<"Enter the position at which it should be deleted: ";
	cin>>delpos;
	
	for(i=delpos;i<n;i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	
	cout<<"\nThe array elements after inserting: ";
	for(i=0;i<n;i++)
		cout<<arr[i]<<'\t';
		
	return 0;
}

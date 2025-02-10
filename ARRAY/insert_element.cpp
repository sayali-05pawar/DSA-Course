//Inserting an element in given array at given position
#include <iostream>
using namespace std;

int main()
{
	int arr[100],n,ins,pos,i;
	cout<<"Enter the size: ";
	cin>>n;
	
	cout<<"Enter the array elements: ";
	for(i=0;i<n;i++)
		cin>>arr[i];
		
	//Insertion Logic
	cout<<"Enter the element to insert: ";
	cin>>ins;
	cout<<"Enter the position at which it should be inserted: ";
	cin>>pos;
	
	for(i=n-1;i>=pos;i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[pos] = ins;
	n++;
	
	cout<<"\nThe array elements after inserting: ";
	for(i=0;i<n;i++)
		cout<<arr[i]<<'\t';
		
	return 0;
}

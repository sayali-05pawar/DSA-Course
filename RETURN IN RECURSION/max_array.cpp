//Find maximum from array
#include <iostream>
using namespace std;

int findmax (int arr[],int size)
{
	int m;
	if(size>0)
	{
		m = findmax(arr,size-1);
		if(m>arr[size-1])
		{
			return m;
		}
		else
			return arr[size-1];
	}
	return arr[0];
}

int main()
{
	int arr[100],s1,z,i;
	
	cout<<"Enter the size of the array: ";
	cin>>s1;
	cout<<"Enter the array elements: ";
	for(i=0;i<s1;i++)
		cin>>arr[i];
		
	z = findmax(arr,s1);
	cout<<"Maximum element from the array is: "<<z;
	
	return 0;
}

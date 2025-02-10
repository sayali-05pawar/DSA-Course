//Searching an element in array
#include <iostream>
using namespace std;

int issearch(int arr[],int size,int a)
{
	int m;
	if(size>0)
	{
		if(a == arr[size])
			return 1;
			
		else
			return issearch(arr,size-1,a);
	}
	return 0;
}

int main()
{
	int arr[100],s1,z,i,num;
	
	cout<<"Enter the size of the array: ";
	cin>>s1;
	cout<<"Enter the array elements: ";
	for(i=0;i<s1;i++)
		cin>>arr[i];

	cout<<"Enter the number to be searched: ";
	cin>>num;	
	z = issearch(arr,s1,num);
	
	if(z==1)
		cout<<"Element found !!!";
	else
		cout<<"Element not found ";
	
	return 0;
}

//DYNAMIC MEMORY ALLOCATION for array as per user demand
#include <iostream>
using namespace std;

int main()
{
	int *a;
	int n,i;
	
	cout<<"Enter the size: ";
	cin>>n;
	
	a = new int[n]; //Dynamic array
	
	cout<<"Enter the array elements: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		/*
			OR
		cin>>*(a+i); location = base_address + ith_index
			OR
		cin>>i[a];
		*/
	}
	
	cout<<"The given array elements are: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<'\t';
		/*
			OR
		cout<<*(a+i); location = base_address + ith_index
			OR
		cout<<i[a];
		*/
	}
	
	return 0;
}

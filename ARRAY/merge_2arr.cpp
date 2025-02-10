//Merging of two sorted arrays
//Ascending order
#include <iostream>
using namespace std;

int main()
{
	int arr1[100],sz1,arr2[100],sz2,arr3[100],i=0,j=0,l=0,k=0;
	
	cout<<"Enter the size of first array: ";
	cin>>sz1;
	
	cout<<"Enter the size of second array: ";
	cin>>sz2;
	
	cout<<"Enter the sorted elements for the first array: ";
	for(i=0;i<sz1;i++)
		cin>>arr1[i];
	
	cout<<"Enter the sorted elements for the second array: ";
	for(i=0;i<sz2;i++)
		cin>>arr2[i];
		
	while(l<sz1 && j<sz2)
	{
		if(arr1[l] < arr2[j])
		{
			arr3[k] = arr1[l];
			k++;
			l++;
		}
		else if(arr2[j] < arr1[l])
		{
			arr3[k] = arr2[j];
			k++;
			j++;
		}
		else if(arr1[l] == arr2[j])
		{
			arr3[k] = arr1[l];
			k++;
			l++;
			arr3[k] = arr2[j];
			k++;
			j++;
		}
	}
	
	//remaining element to be copy in arr3
	while(l<sz1)
	{
		arr3[k] = arr1[l];
			k++;
			l++;
	}
	while(j<sz2)
	{
		arr3[k] = arr2[j];
			k++;
			j++;
	}
	cout<<"MERGING SORT: ";
	for(i=0;i<k;i++)
		cout<<arr3[i]<<'\t';
		
	return 0;
}

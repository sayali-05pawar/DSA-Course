#include <iostream>
using namespace std;

int main()
{
	int a[100],n,temp=0,i,j;
	cout<<"Enter the array size: ";
	cin>>n;
	cout<<"Enter the array elements: ";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"The given array is: ";
	for(i=0;i<n;i++)
		cout<<a[i]<<"  ";
	
	//BUBBLE SORT LOGIC
	/*for(j=0;j<n;j++)
	{
		for(i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1]) //for ascending order
			{
			temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
			}
		}
	}
	cout<<"\nBubble sort: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}*/
	
	//IMPROVED BUBBLE SORT LOGIC
	for(j=0;j<n;j++)
	{
		for(i=0;i<n-j;i++)
		{
			if(a[i]>a[i+1]) //for ascending order
			{
			temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
			}
		}
	}
	cout<<"\nBubble sort: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int a[100],n,i,j,val=0;
	cout<<"Enter the size: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter "<<i<<" element:";
		cin>>a[i];
	}
	
	//INSERTION SORT LOGIC
	for(j=0;j<n;j++)
	{
		val = a[j];
			
		for(i=j-1;i>=0 && a[i]>val;i--)
		{
			a[i + 1] = a[i];
		}
		
		a[i + 1] = val;
	}
	
	cout<<"\nINSERTION SORT: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}

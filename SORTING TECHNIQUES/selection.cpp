#include <iostream>
using namespace std;

int main()
{
	int a[100],n,i,j,min=0,pos=0;
	cout<<"Enter the size: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter "<<i<<" element:";
		cin>>a[i];
	}
	
	//SELECTION SORT LOGIC
	for(j=0;j<n;j++)
	{
		min = a[j];
		pos = j;
		
		for(i=j+1;i<n;i++)
		{
			if(min>a[i])
			{
				min = a[i];
				pos = i;
			}
		}
		
		a[pos] = a[j];
		a[j] = min;
	}
	
	cout<<"\nSELECTION SORT: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}

//BINARY SEARCH
#include <iostream>
using namespace std;

int main()
{
	int a[100],sz,num,f=0,i,mid=0,low=0,high;
	
	cout<<"Enter the size of array: ";
	cin>>sz;
	
	cout<<"Enter sorted array elments: ";
	for(i=0;i<5;i++)
		cin>>a[i];
		
	cout<<"\nEnter the number to be searched: ";
	cin>>num;
	
	//LOGIC
	high = sz-1;
	while(low <= high)
	{
		mid = low+high / 2;
		if(a[mid] == num)
		{
			f=1;
			break;
		}
		else if(a[mid] > num)
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	if (f==1)
		cout<<"NUMBER FOUND!!!";
	else
		cout<<"NUMBER NOT FOUND!!!";
		
	return 0;
}


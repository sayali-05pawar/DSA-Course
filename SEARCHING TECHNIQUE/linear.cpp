#include <iostream>
using namespace std;

int issearch(int x,int arr[5])
{
	int i,s;
	for(i=0;i<5;i++)
		if(x == arr[i])
			return i;
	
	return -1; //because -1 doesn't exist in array indexing it will be false
}

int main()
{
	int num,i,arr[5],c;
	
	cout<<"Enter array elments: ";
	for(i=0;i<5;i++)
		cin>>arr[i];
		
	cout<<"\nEnter the number to be searched: ";
	cin>>num;
	
	c = issearch(num,arr);
	
	if(c>0)
		cout<<"\nNumber is found at "<<c<<" index ";
		
	else
		cout<<"\nNumber not found ";
		
		
	return 0;
}

//Max between 3 arrays
//using same size
#include <iostream>
using namespace std;

int findmax(int arr[5])
{
	int max,i;
	max=arr[0];
	for(i=0;i<5;i++)
		if(max<arr[i])
			max=arr[i];
	
	return max;	
}

int great(int a,int b,int c)
{
	if (a>b && a>c)
		return a;
	else if(b>c)
		return b;
	else
		return c;
}
int main()
{
	int a1[5],a2[5],a3[5],i,x;
	cout<<"Enter the 1st array elements: ";
	for(i=0;i<5;i++)
		cin>>a1[i];
		
	cout<<"Enter the 2nd array elements: ";
	for(i=0;i<5;i++)
		cin>>a2[i];
		
	cout<<"Enter the 3rd array elements: ";
	for(i=0;i<5;i++)
		cin>>a3[i];
		
	x=great(findmax(a1),findmax(a2),findmax(a3));
	
	cout<<"\nMaximum between the 3 array elements is: "<<x;
	
	return 0;
}

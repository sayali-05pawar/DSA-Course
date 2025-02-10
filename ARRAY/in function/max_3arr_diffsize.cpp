//Max between 3 arrays
//using different size
#include <iostream>
using namespace std;

int findmax(int arr[100],int size)
{
	int max,i;
	max=arr[0];
	for(i=0;i<size;i++)
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
	int a1[100],a2[100],a3[100],s1,s2,s3,i,x;
	
	cout<<"Enter the size of 1st array: ";
	cin>>s1;
	cout<<"Enter the size of 2nd array: ";
	cin>>s2;
	cout<<"Enter the size of 3rd array: ";
	cin>>s3;
	
	cout<<"Enter the 1st array elements: ";
	for(i=0;i<s1;i++)
		cin>>a1[i];
		
	cout<<"Enter the 2nd array elements: ";
	for(i=0;i<s2;i++)
		cin>>a2[i];
		
	cout<<"Enter the 3rd array elements: ";
	for(i=0;i<s3;i++)
		cin>>a3[i];
		
	x=great(findmax(a1,s1),findmax(a2,s2),findmax(a3,s3));
	
	cout<<"\nMaximum between the 3 array elements is: "<<x;
	
	return 0;
}

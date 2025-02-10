//power of x raise to y
#include <iostream>
using namespace std;

int pow(int a,int b)
{
	if(b>=1)
	{
		int res = pow(a,b-1) * a;
		return res;
	}
	return 1;
}
/*int pow(int a,int b)
{
	if(b>=1)
	{
		return res = pow(a,b-1) * a;
	}
	return 1;
}*/

int main()
{
	int x,y,s;
	cout<<"Enter X: ";
	cin>>x;
	cout<<"Enter Y: ";
	cin>>y;
	
	s = pow(x,y);
	cout<<"Power of x raise to y is: "<<s;
	return 0;
}

//Sum of numbers from 1 to 5
#include <iostream>
using namespace std;

int sum(int a)
{
	int x;
	if(a<=5)
	{
		x=sum(a+1) + a;
		return x;
	}
	return 0;
}
/*int sum(int a)
{
	int x;
	if(a<=5)
	{
		return sum(a+1) + a;
	}
	return 0;
}*/

int main()
{
	int s;
	s = sum(1);
	cout<<"Sum is: "<<s;
	
	return 0;
}

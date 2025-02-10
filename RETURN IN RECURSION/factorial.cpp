//Factorial of given number
#include <iostream>
using namespace std;

int fact(int a)
{
	int x;
	if(a>0)
	{
		x = (fact(a-1) * a);
		return x;
	}
	return 1;
}
/*int fact(int a)
{
	int x;
	if(a>0)
	{
		return (fact(a-1) * a);
	}
	return 1;
}*/

int main()
{
	int s;
	s = fact(4);
	cout<<"Factorial of given number is: "<<s;
	
	return 0;
}

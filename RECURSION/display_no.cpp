//WAP tp display 1 to 10 no's & 10 to 1
#include <iostream>
using namespace std;

void f1(int a)
{
	if(a<=10)
	{
		//cout<<a<<'\t'; //no from 1 to 10
		f1(a+1);
		cout<<a<<'\t'; //no from 10 to 1
	}
}

int main()
{
	f1(1);
	return 0;
	
}

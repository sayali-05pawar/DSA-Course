//Conversion of decimal to binary
#include <iostream>
using namespace std;

void bin(int no)
{
	int rem;
	if(no>0)
	{
		rem = no%2;
		bin(no/2);
		cout<<rem;
	}
}

int main()
{
	int num;
	cout<<"\nEnter a number: ";
	cin>>num;
	bin(num);
	
	return 0;
}

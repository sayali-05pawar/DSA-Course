#include <iostream>
using namespace std;

int main()
{
	int i=100;
	cout<<"\nThe numbers from 1 to 100: ";
	/*while (i>=1)
	{
		cout<<i<<'\t';
		i--;
	}*/
	do
	{
		cout<<i<<'\t';	
		i--;
	}
	while(i>=1);
	return 0;
}

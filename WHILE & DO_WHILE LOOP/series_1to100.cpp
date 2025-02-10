#include <iostream>
using namespace std;

int main()
{
	int i=1;
	cout<<"\nThe numbers from 1 to 100: ";
	/*while (i<=100)
	{
		cout<<i<<'\t';
		i++;
	}*/
	do
	{
		cout<<i<<'\t';
		i++;	
	}
	while(i<=100);
	return 0;
}

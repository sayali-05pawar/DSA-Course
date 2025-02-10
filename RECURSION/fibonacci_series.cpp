#include <iostream>
using namespace std;

void fibb(int a,int b,int n)
{
	int c;
	if(n>0)
	{
		c = a+b;
		cout<<c<<" ";
		fibb(b,c,n-1);
	}
}

int main()
{
	int num;
	cout<<"\nEnter a limit: ";
	cin>>num;
	
	fibb(1,0,num);
	
	return 0;
}

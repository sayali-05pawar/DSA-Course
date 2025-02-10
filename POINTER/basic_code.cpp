//Basic Pointer Code
#include <iostream>
using namespace std;

int main()
{
	int a = 10,b = 20;
	int *p;
	
	p = &a;
	cout<<"a = "<<*p;
	
	p = &b;
	cout<<"\nb = "<<*p;
	
	return 0;
}


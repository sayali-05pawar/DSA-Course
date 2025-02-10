//WAP to find out greatest between 3no's
#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	
	cout<<"Enter the first number: ";
	cin>>a;
	cout<<"Enter the second number: ";
	cin>>b;
	cout<<"Enter the third number: ";
	cin>>c;

	//LOGIC-1	
	if(a>b && a>c)
		cout<<a;
	if(b>c && b>a)
		cout<<b;
	if(c>a && c>b)
		cout<<c;
	
	//LOGIC-2
	/*if(a>b && a>c)
		cout<<a;
	else if(b>c)
		cout<<b;
	else
		cout<<c;*/
		
	//LOGIC-3
	/*if(a>b)
	{
		if(a>c)
			cout<<a;
		else
			cout<<c;
	}
	else
	{
		if(b>c)
			cout<<b;
		else
			cout<<c;
	}*/
	
	//LOGIC-4
	/*max = a;
	if(max<b)
		max = b;
	if(max<c)
		max = c;
	cout<<max;*/	
	
	/*Sequence for best algorithm:-
		logics: 2,3,1,4*/
		
	return 0;		
}

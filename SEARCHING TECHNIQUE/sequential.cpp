/*SEQUENTIAL SEARCH or LINEAR SEARCH*/
#include <iostream>
using namespace std;

int main()
{
	int a[5],num,f=0,i;
	
	cout<<"Enter array elments: ";
	for(i=0;i<5;i++)
		cin>>a[i];
		
	cout<<"\nEnter the number to be searched: ";
	cin>>num;
	
	//LOGIC-1
	for(i=0;i<5;i++)
	{
		if(a[i] == num)
		{
			f = 1;
			break;
		}
	}
	if(f == 1)
		cout<<"NUMBER FOUND!!!";
	else
		cout<<"NUMBER NOT FOUND!!!";
		
	//LOGIC-2
	/*bool search(int a[5],int 5)
	{
		for(int i=0;i<5;i++)
			if(a[i] == no)
				return true;
				
		return false;
	}*/
	
	return 0;
}

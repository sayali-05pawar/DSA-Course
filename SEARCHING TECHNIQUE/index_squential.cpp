/*INDEX SEQUENTIAL SEARCH :- searching an element in sorted array */
#include <iostream>
using namespace std;

int main()
{
	int a[5],num,f=0,i;
	
	cout<<"Enter sorted array elments: ";
	for(i=0;i<5;i++)
		cin>>a[i];
		
	cout<<"\nEnter the number to be searched: ";
	cin>>num;
	
	for(i=0;i<5 && a[i]<num;i++);
	/*or for(i=0;i<5 && a[i]<num;i++)
	{};*/
	
	if (a[i] == num)
		cout<<"NUMBER FOUND!!!";
	else
		cout<<"NUMBER NOT FOUND!!!";
		
	return 0;
}

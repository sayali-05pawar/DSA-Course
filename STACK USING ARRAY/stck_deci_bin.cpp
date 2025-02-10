#include <iostream>
using namespace std;

int data[10];
int top = 0;

class stack
{	
	public:
	stack()
	{
		top = -1;	
	}	
	void push(int no)
	{
		top ++;
		data[top] = no;
	}
	int pop()
	{
		int no;
		no = data[top];
		top -- ;
		return no;	
	}
	bool isempty()
	{
		if(top == -1)
			return true;
		return false;
	}
	bool isfull()
	{
		if(top == 9)
			return true;
		return false;
	}
};
void display()
{
	cout<<"\nThe elements in the stack are: ";
	for(int i=0;i<=top;i++)
		cout<<data[i]<<'\t';
}

int main()
{
	stack s;
	int num;
	
	cout<<"Enter a Decimal number: ";
	cin>>num;
	
	while(num != 0)
	{
		s.push(num%2);
		num = num / 2;	
	}
	
	cout<<"\nThe Binary Number is: ";	
	while(!s.isempty())
		cout<<s.pop();
	
	return 0;
}


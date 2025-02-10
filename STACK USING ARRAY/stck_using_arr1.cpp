#include <iostream>
using namespace std;

int top = -1;
int arr[100];

class stack
{
	public:
		
		void push (int x);
		int pop();
};

void stack :: push(int x)
{
	if(top >= 100-1)
	{
		cout<<"\nSTACK IS OVERFLOW !!!";
	}
	else
	{
		arr[++top] = x;
		cout<<x<<" is pushed into stack "<<endl;
	}
}

int stack :: pop()
{
	if(top == -1)
	{
		cout<<"\nSTACK IS EMPTY !!!";
		return 0;
	}
	else
	{
		int y = arr[top--];
		return y;
	}
}

void display()
{
	cout<<"\nThe elements in the stack are: ";
	for(int i=0;i<top+1;i++)
		cout<<arr[i]<<'\t';
}

int main()
{
	stack s;
	int choice,num;
	char ch;
	do{
		cout<<"\nMENU: "
			<<"\n1.push "
			<<"\n2.pop "
			<<"\n3.display "
			<<"\n----------------------------";
			
		cout<<"\nEnter your choice: ";
		cin>>choice;
		
		switch (choice)
		{
			case 1: {
						cout<<"Enter a number to be push in stack: ";
						cin>>num;
						s.push(num);
						break;
					}
					
			case 2: {
						cout<<"\n";
						cout<<s.pop()<<" popped from stack";
						break;
					}
					
			case 3: display();
					break;
					
			default:
				cout<<"\nEnter a valid choice !!!";
		}
		cout<<"\n--------------------------------";
		cout<<"\nDo you want to repeat??? \nIf yes press 'y' else press 'n': ";
		cin>>ch;
		
	}while(ch == 'y');
	
	cout<<"\n-----------THANK YOU-----------\n";
	
	return 0;
}

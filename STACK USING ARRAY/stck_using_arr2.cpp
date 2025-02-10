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
		cout<<no<<" is pushed into stack "<<endl;
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

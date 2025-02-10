#include <iostream>
#include<string>
using namespace std;

const int MAX_ITEMS = 100;

class ShoppingCart
{	
    private:
        string items[MAX_ITEMS];
        int top;
	public:
	ShoppingCart()
	{
		top = -1;	
	}	
	void push(string item)
	{
        if(isfull())
        {
            cout<<"Shopping cart is full!!! Cannot add more items."<<endl;
            return;
        }
		top ++;
		items[top] = item;
		cout<<item<<" has been added to the shopping cart. "<<endl;
	}
	string pop()
	{
        if(isempty())
        {
            cout<<"Shopping cart is empty!!! No items to remove."<<endl;
            return;
        }
		string item;
		item = items[top];
		top -- ;
		return item;	
	}
    void displayitems()
    {
        if(isempty())
        {
            cout<<"Shopping cart is empty!!!"<<endl;
            return;
        }
	    cout<<"\nItems in the shopping cart: "<<endl;
	    for(int i=0;i<=top;i++)
		    cout<<"-"<<items[i]<<endl;
    }
	bool isempty()
	{
		if(top == -1)
			return true;
		return false;
	}
	bool isfull()
	{
		if(top == MAX_ITEMS - 1)
			return true;
		return false;
	}
};

int main()
{
	ShoppingCart s;
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

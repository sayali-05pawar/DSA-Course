#include <iostream>
using namespace std;

class Node
{
	public: 
	int data;
	Node *next;
	Node()
	{
		data = 0;
		next = NULL;	
	}	
};

class stack
{
	Node *top;
	public:
	stack()
	{
		top = NULL;	
	}	
	void push(int no)
	{
		Node *nnode;
		nnode = new Node;
		
		if(nnode == NULL)
		{
			cout<<"\nSTACK IS OVERFLOW "; //logic for isfull()
		}
		else
		{
            nnode->data = no; // Set the data member

            if (top == NULL)
			{
                top = nnode;
            }
			else
			{
                nnode->next = top;
                top = nnode;
            }
        }
		
	}
	int pop()
	{
		int n;
		Node *x;
		
		if (top == NULL)
		{
            cout << "\nSTACK IS UNDERFLOW ";
            return -1; // Return an error value
        }
        
		n = top -> data;
		x = top;
		top = top -> next;
		
		delete x;
		return n;
	}
	int isempty()
	{
		if (top == NULL)
			return 1;
			
		return 0;
	}
	void display()
	{
		Node *temp;
		for (temp = top; temp != NULL; temp = temp -> next )
			cout<<temp -> data<<'\t';
	}
};

int main()
{
	stack s;
	s.push(9);
	s.push(2);
	s.push(99);
	s.push(21);
	s.push(7);
	
	s.display();
	return 0;
}

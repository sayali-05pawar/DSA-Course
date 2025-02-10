//Program of collection of numeric data i.e numbers
#include <iostream>
using namespace std;

class Node
{
	public:
	int no; //data member
	Node *next; //data member //points to next address in node
	Node() //default constructor
	{
		no = 0;
		next = NULL;	
	}	
};

class linkedlist
{
	Node *start; //Class Aggregation 
				//it will store address of first node //data member
	public:
	linkedlist() //default constructor
	{
		start = NULL;
	}
	
	void create() //member function 
	{
		Node *nnode; //will search and allocate new memory
		Node *temp;
		char ch;
		do{
			nnode = new Node; //search new memory and allocate //dynamic memory allocation
			cout<<"Enter the number to be stored: ";
			cin>>nnode -> no;
			
			if(start == NULL) //check whether it is the first node or not
			{
				start = nnode;
			}
			else 
			{
				temp = start;
				while (temp -> next != NULL)
					temp = temp -> next;
				temp -> next = nnode;
			}
			cout<<"Do you have more data ?? \nIf yes than press 'y' else press 'n': ";
				cin>>ch;
		}
		while (ch == 'y');
	}
	
	void display()
	{
		Node *temp;
		cout<<"\nThe store numbers are: ";
		for (temp = start;temp != NULL;temp = temp -> next)
		{
			cout<<temp -> no<<'\t';
		}
	}
};



int main()
{
	linkedlist l;
	l.create();
	l.display();;
	return 0;
}

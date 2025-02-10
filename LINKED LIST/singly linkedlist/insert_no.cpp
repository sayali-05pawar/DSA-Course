#include <iostream>
using namespace std;

class Node
{
	public: 
	int no;
	Node *next;
	Node()
	{
		no = 0;
		next = NULL;	
	}	
};

class insert
{
	Node *start;
	public:
	insert()
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
	
	void ins_beg()
	{
		Node *nnode,*temp;
		
		nnode = new Node;
		cout<<"Enter a number to  be insert at begin: ";
		cin>>nnode -> no;
		
		nnode -> next = start;
		start = nnode;
		
		display();
	}
	
	void ins_between()
	{
		Node *nnode,*temp;
		int num;
		
		nnode = new Node;
		cout<<"\nEnter a number to be insert: ";
		cin>>nnode -> no;
		
		cout<<"Enter the number after which you want to insert: ";
		cin>>num;
		for (temp = start;temp != NULL;temp = temp -> next)
		{
			if(temp -> no == num)
			{
				nnode -> next = temp -> next;
				temp -> next = nnode;
				break;
			}
		}
		
		display();
	}
	
	void ins_end()
	{
		Node *nnode,*temp;
		
		nnode = new Node;
		cout<<"\nEnter a number to be inserted at end: ";
		cin>>nnode -> no;
		
		for (temp = start;temp -> next != NULL;temp = temp -> next)
		{ };
			temp -> next = nnode;
			
		display();
	}
};

int main()
{
	insert l;
	int choice;
	char ch;
	do{
    	cout<<"MENU: "
    		<<"\n1.Store data"
    		<<"\n2.Display data"
    		<<"\n3.Insert data at beginning"
    		<<"\n4.Insert data in between any position "
    		<<"\n5.Insert data at end"
    		<<"\n---------------------------------------------------------";
    		
    	cout<<"\nEnter the menu number: ";
		cin>>choice;	

    	switch (choice) {
        	case 1: 
			{
            	l.create();
            	break;
        	}
        	case 2: 
			{
            	l.display();
            	break;
        	}
        	case 3: 
			{
            	l.ins_beg();
            	break;
        	}
        	case 4: 
			{
            	l.ins_between();
            	break;
        	}
        	case 5: 
			{
            	l.ins_end();
            	break;
        	}
        
        	default:
            	cout << "\nInvalid choice! Please enter a valid choice: ";
            	break;
    		}
    	cout<<"\n__________________________________________";
    	cout<<"\nDou you want to repeat???\nIf yes press 'y' else press 'n': ";
    	cin>>ch;
		}
		while (ch == 'y');	
	
	cout<<"\n\n-------------THANK YOU-------------\n\n";
	return 0;	
}








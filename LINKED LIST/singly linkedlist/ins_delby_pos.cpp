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

class ins_del
{
	Node *start;
	public:
	ins_del()
	{
		start = NULL;	
	}
	
	void create()  
	{
		 Node *nnode;  // Declare a pointer to a Node
    	 Node *temp;    // Temporary pointer to traverse the linked list
   		 char ch;       // Variable to hold user input for continuing data entry
		do{
			nnode = new Node;   // Allocate memory for a new Node
			cout<<"Enter the number to be stored: ";  
			cin>>nnode -> no;   // Read user input and store in the 'no' member of the Node
			
			if(start == NULL) 
			{
				start = nnode;  // If the list is empty, make 'start' point to the new Node
			}
			else 
			{
				temp = start; 	// Start traversing from the beginning of the list
				while (temp -> next != NULL)
					temp = temp -> next; 	// Move to the next Node in the list
				temp -> next = nnode;  // Insert the new Node at the end of the list
			}
			cout<<"Do you have more data ?? \nIf yes than press 'y' else press 'n': ";
				cin>>ch;  // Ask user if they want to enter more data
		}
		while (ch == 'y');  // Repeat the loop if user wants to enter more data
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
	
	void ins_by_pos()
	{
		Node *nnode,*temp;
		int pos,i;
		
		nnode = new Node;
		cout<<"\nEnter a number to be insert: ";
		cin>>nnode -> no;
		
		cout<<"Enter the position at which you want to insert: ";
		cin>>pos;
		
		if (pos==1)
		{
			nnode -> next = start;
			start = nnode;
		}
		else
		{
			int f=0;
			for (temp = start,i=1;temp != NULL;temp = temp -> next,i++)
			{
				if(i==pos-1)
				{
					nnode -> next = temp -> next;
					temp -> next = nnode;
					f=1;
					break;
				}
			}
			if (f==0)
			{
				for (temp = start;temp -> next != NULL;temp = temp -> next)
					{ };
				temp -> next = nnode;	
			}
		}
				
		display();
	}

	void del_by_pos()
	{
		Node *x,*nnode,*temp;
		int pos,i;
				
		cout<<"Enter the position which you want to delete: ";
		cin>>pos;
		
		if(pos==1)
		{
			x = start;  
			start = start -> next;  
			delete x;
		}
		else
		{
			int f=0;
			for (temp = start,i=1;temp != NULL;temp = temp -> next,i++)
			{
				if(i==pos-1) 
				{
					x = temp -> next;			
					temp -> next = x -> next;	
					delete x;
					f=1;					
					break;						
				}
			}
			if(f==0)
			{
				for (temp = start;temp -> next -> next != NULL;temp = temp -> next)
				{ };
				x= temp -> next;	
				temp -> next = NULL; 
				delete x;
			}
		}
		
		display();
	}
};

int main()
{
	ins_del l;
	int choice;
	char ch;
	do{
    	cout<<"\nMENU: "
    		<<"\n1.Store data"
    		<<"\n2.Display data"
    		<<"\n3.Insert data"
    		<<"\n4.Delete data"
    		<<"\n------------------------------------------------";
    		
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
            	l.ins_by_pos();
            	break;
        	}
        	case 4: 
			{
            	l.del_by_pos();
            	break;
        	}
        	
        	default:
            	cout << "\nInvalid choice! Please enter a valid choice !!!!! ";
            	break;
    		}
    	cout<<"\n----------------------------------------------";
    	cout<<"\nDou you want to repeat???\nIf yes press 'y' else press 'n': ";
    	cin>>ch;
		}
		while (ch == 'y');	
	
	cout<<"\n\n-------------THANK YOU-------------\n\n";
	return 0;	
}

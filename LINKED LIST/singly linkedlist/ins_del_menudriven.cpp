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
	
	void del_beg()
	{
		Node *x; //'x' points to the node that shall be deleted
		
		x = start;  // Store the address of the current start node in 'x'
		start = start -> next;  // Move 'start' to point to the next node
		delete x;  // Delete the node pointed to by 'x'
		
		display();
	}
	
	void del_between()
	{
		Node *x,*nnode,*temp;
		int num;
				
		cout<<"Enter the number which you want to delete: ";
		cin>>num;
		for (temp = start;temp != NULL;temp = temp -> next)
		{
			if(temp -> next -> no == num)  //next node with 'no' of the next node matches
			{
				x = temp -> next;			// Store the address of the node to be deleted in 'x'
				temp -> next = x -> next;	// Adjust the 'next' pointer of the previous node
				delete x;					// Delete the node pointed to by 'x'
				break;						//Exit loop
			}
		}
		
		display();
	}
	
	void del_end()
	{
		Node *x,*temp;
		
		// Traverse the list until the second last node
		for (temp = start;temp -> next -> next != NULL;temp = temp -> next)
		{ };
			x= temp -> next;	// Store the address of the last node in 'x'
			temp -> next = NULL; // Set the next pointer of the second last node to NULL
			delete x;				// Delete the last node
				
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
    		<<"\n3.Insert data at beginning"
    		<<"\n4.Insert data in between any position "
    		<<"\n5.Insert data at end"
    		<<"\n6.Delete data of beginning"
    		<<"\n7.Delete data of an position in between"
    		<<"\n8.Delete data of end"
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
        	case 6: 
			{
            	l.del_beg();
            	break;
        	}
        	case 7: 
			{
            	l.del_between();
            	break;
        	}
        	case 8: 
			{
            	l.del_end();
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


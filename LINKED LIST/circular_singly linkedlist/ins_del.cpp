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
		 Node *nnode;  
    	 Node *temp;    
   		 char ch;       
		do{
			nnode = new Node;   
			cout<<"Enter the number to be stored: ";  
			cin>>nnode -> no;   
			
			if(start == NULL) 
			{
				start = nnode;  
				nnode -> next = start;
			}	
			else 
			{
				 temp = start;
                while (temp->next != start) {
                    temp = temp->next;
                }
                temp->next = nnode;
                nnode->next = start;
			}
			cout<<"Do you have more data ?? \nIf yes than press 'y' else press 'n': ";
				cin>>ch;  
		}
		while (ch == 'y');  
	}
	
	void display()
	{
		Node *temp = start;
		cout<<"\nThe store numbers are: ";
		 do {
            cout << temp->no << '\t';
            temp = temp->next;
        } while (temp != start);
	}
	
	void ins_beg()
	{
		Node *nnode,*temp;
		
		nnode = new Node;
		cout<<"Enter a number to  be insert at begin: ";
		cin>>nnode -> no;
		
		if (start == NULL)
		{
        // If the list is empty, insert as the first node
        start = nnode;
        nnode->next = start;
    	} 
		else
		{
		for(temp = start;temp->next != start;temp = temp->next);
                
		nnode -> next = start;
		start = nnode;
		temp -> next = start;
		}
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
		for (temp = start;temp != start;temp = temp -> next)
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
		
		if (start == NULL)
		{
        // If the list is empty, insert nnode as the first node
        start = nnode;
        nnode->next = start;
    	}
    	else
    	{
		for (temp = start;temp -> next != start;temp = temp -> next)
		{ };
			temp -> next = nnode;
			nnode -> next = start;
		}
		display();	
	}
	
	void del_beg()
	{
		Node *temp; //'x' points to the node that shall be deleted
		Node *x=start;
		
		for (temp = start;temp -> next != start;temp = temp -> next)
		{ };
		if (temp == start) //only one node
		{ 
        	start = NULL;
        	cout<<"\nThere is no data in linked list !!";
    	}
		else
		{
			start = start->next; 
        	temp->next = start;
        	display();
		}
		delete x;  // Delete the node pointed to by 'x'
	}
	
	void del_between()
	{
		Node *x,*temp=start;
		int num;
				
		cout<<"Enter the number which you want to delete: ";
		cin>>num;
		for (temp = start;temp != start;temp = temp -> next)
		{
			if(temp -> next -> no == num)  //next node with 'no' value
			{
				x = temp -> next;			
				temp -> next = x -> next;	
				delete x;
				
				/*if(x==temp -> next -> next)
				{
					temp -> next -> next = temp -> next;
				}	*/				
				break;						//Exit loop
			}
		}
		
		display();
	}
	
	void del_end()
	{
    	Node *x, *temp;

    	// Check if the list is empty
    	if (start == NULL) 
    	{
        	cout << "\nList is empty. Cannot delete from an empty list !!!";
    	}
    	else if (start->next == start)  // Check if there's only one node in the list
    	{
        	// Only one node present
        	x = start;
        	start = NULL;               // Set start to NULL, making the list empty
        	delete x;
        	cout << "\nThe list is now empty.";
    	}
    	else
    	{
    	    // Traverse the list until the second last node
    	    for (temp = start; temp->next->next != start; temp = temp->next)
    	    { };

    	    x = temp->next;            // Store the last node in 'x'
    	    temp->next = start;        // Set the second last node's next pointer to 'start' (circular behavior)
    	    delete x;                  // Delete the last node
    	    display();                 // Display the list after deletion
    	}
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


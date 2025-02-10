#include <iostream>
using namespace std;

class Node
{
	public: 
	int no;
	Node *next,*prev;
	Node()
	{
		no = 0;
		next = NULL;
		prev = NULL;	
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
			}
			else 
			{
				for (temp = start;temp -> next != NULL;temp = temp -> next);
				temp -> next = nnode;
				nnode -> prev = temp;
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
	
	void dis_rev()
	{
		Node *temp;
		cout<<"\nReversing the numbers: ";
		for (temp = start;temp -> next != NULL;temp = temp -> next);
		for (;temp != NULL;temp = temp -> prev)
			cout<<temp -> no<<'\t';
	}
	void ins_beg()
	{
		Node *nnode,*prev,*temp;
		
		nnode = new Node;
		cout<<"Enter a number to  be insert at begin: ";
		cin>>nnode -> no;
		
		nnode -> next = start;
		start -> prev = nnode;
		start = nnode;
		
		display();
		dis_rev();
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
				nnode->next = temp->next;
				temp->next = nnode;
				nnode->prev = temp;
				nnode->next->prev = nnode;
				break;
			}
		}
		
		display();
		dis_rev();
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
			nnode -> prev = temp;
			
		display();
		dis_rev();	
	}
	
	void del_beg()
	{
		Node *x,*prev,*temp;
		
		x = start;  
		start = start -> next;  
		start -> prev = NULL;
		delete x;  
		
		display();
		dis_rev();
	}
	
	void del_between() 
	{
		Node *x,*nnode,*temp;
		int num;
				
		cout<<"Enter the number which you want to delete: ";
		cin>>num;
		for (temp = start;temp != NULL;temp = temp -> next)
		{
			if(temp -> no == num)  //current node with 'no' value
			{
				x = temp ;			
				temp -> prev-> next = temp-> next;	
                temp->next->prev = temp->prev; 

				delete x;					
				break;						
			}
		}
		
		display();
		dis_rev();
	}
	
	void del_end()
	{
		Node *x,*temp;
		
		// Traverse to the second-to-last node
		for (temp = start;temp -> next  -> next != NULL;temp = temp -> next)
		{ };
			x = temp -> next; // Last node
			temp -> next = NULL;// Disconnect the last node
			delete x;
				
		display();
		dis_rev();
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
    		<<"\n3.Display reverse data"
    		<<"\n4.Insert data at beginning"
    		<<"\n5.Insert data in between any position "
    		<<"\n6.Insert data at end"
    		<<"\n7.Delete data of beginning"
    		<<"\n8.Delete data of an position in between"
    		<<"\n9.Delete data of end"
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
            	l.dis_rev();
            	break;
        	}
        	case 4: 
			{
            	l.ins_beg();
            	break;
        	}
        	case 5: 
			{
            	l.ins_between();
            	break;
        	}
        	case 6: 
			{
            	l.ins_end();
            	break;
        	}
        	case 7: 
			{
            	l.del_beg();
            	break;
        	}
        	case 8: 
			{
            	l.del_between();
            	break;
        	}
        	case 9: 
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


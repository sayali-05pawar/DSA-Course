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

class deletion
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
	
	void del_beg()
	{
		Node *x,*temp;
		
		x = start;
		start = start -> next;
		delete x;
		
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
			if(temp -> next -> no == num)
			{
				x = temp -> next;
				temp -> next = x -> next;
				delete x;
				break;
			}
		}
		
		display();
	}
	
	void del_end()
	{
		Node *x,*temp;
		
		for (temp = start;temp -> next -> next != NULL;temp = temp -> next)
		{ };
			x= temp -> next;
			temp -> next = NULL;
			delete x;
			
		display();	
	}
};

int main()
{
	deletion d;
	int choice;
	char ch;
	do{
    	cout<<"MENU: "
    		<<"\n1.Store data"
    		<<"\n2.Display data"
    		<<"\n3.Delete data of beginning"
    		<<"\n4.Delete data of an position in between"
    		<<"\n5.Delete data of end"
    		<<"\n---------------------------------------------------------";
    		
    	cout<<"\nEnter the menu number: ";
		cin>>choice;		

    	switch (choice) {
        	case 1: 
			{
            	d.create();
            	break;
        	}
        	case 2: 
			{
            	d.display();
            	break;
        	}
        	case 3: 
			{
            	d.del_beg();
            	break;
        	}
        	case 4: 
			{
            	d.del_between();
            	break;
        	}
        	case 5: 
			{
            	d.del_end();
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


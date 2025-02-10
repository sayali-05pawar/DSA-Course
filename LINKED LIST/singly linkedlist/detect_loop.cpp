/*Detecting a loop in a linked list is a common problem in data structures. 
The most efficient solution to detect a loop uses "Floyd’s Cycle-Finding Algorithm", 
also known as the "Tortoise and Hare" approach*/

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

class linkedlist
{
	Node *start; 
				
	public:
	linkedlist() 
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
				temp = start;
				while (temp -> next != NULL)
					temp = temp -> next;
				temp -> next = nnode;
			}
			cout<<"Do you have more data (y/n)?? :";
				cin>>ch;
		}
		while (ch == 'y' || ch == 'Y');
	}
	
    bool detect_loop()
    {
        Node *slow_ptr = start;
        Node *fast_ptr = start;

        while (fast_ptr != nullptr && fast_ptr->next != nullptr) 
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;

            // If the slow and fast pointers meet, a loop is detected
            if (slow_ptr == fast_ptr) 
            {
                return true;
            }
        }

        // No loop detected
        return false;
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
    if(l.detect_loop())
    {
        cout<<"Loop detected in the linked list" << endl;
    }
    else
    {
        cout << "No loop detected in the linked list" << endl;
    }
	l.display();
	return 0;
}
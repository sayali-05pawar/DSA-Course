/*print the middle element of the given singly linkedlist without counting the total number of nodes */
/*To find the middle element of a singly linked list without counting the total number of nodes, we can use 
the "two-pointer" approach (also known as the "tortoise and hare" algorithm). Here's how it works:

-Maintain two pointers: one (slow_ptr) and one (fast_ptr).
-Move slow_ptr by one step and fast_ptr by two steps.
-When fast_ptr reaches the end of the list, slow_ptr will be at the middle of the list.*/

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
	
    void middle()
    {
        Node *slow_ptr = start;
        Node *fast_ptr = start;

         if (start != nullptr) 
        {
            while (fast_ptr != nullptr && fast_ptr->next != nullptr) 
            {
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next->next;
            }
            cout << "The middle element is: " << slow_ptr->no << endl;
        }
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
    l.middle();
	l.display();;
	return 0;
}

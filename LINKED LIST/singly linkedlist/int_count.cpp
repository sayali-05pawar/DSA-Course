/*write a function that counts the number of times a given int occurs in a linked list in c++*/
/*he countOccurrences() function traverses the list and counts how many times the specified integer value appears:
It iterates through the list starting from the head.
For each node, it checks if the node's data matches the given value.
If it does, it increments the count*/

/*Creates a linked list and appends values: 1 -> 2 -> 3 -> 2 -> 2 -> 4.
Calls the countOccurrences() function to count how many times the number 2 appears in the list (which is 3 times).
Prints the result.*/

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
			cout<<"Do you have more data (y/n)?? : ";
				cin>>ch;
		}
		while (ch == 'y');
	}
	
     // Function to count occurrences of a given integer
    int countOccurrences(int value)
    {
        Node* temp = start;
        int count = 0;

        while (temp != nullptr)
        {
            if (temp->no == value)
            {
                count++;
            }
            temp = temp->next;
        }

        return count;
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
    int n;
    linkedlist l;

    l.create();
    cout<<"\nEnter which int no you have to count: ";
    cin>>n;
    int x = l.countOccurrences(n);
    cout<<"The count of "<<n<<" is: "<<x<<endl;
	l.display();
	return 0;
}

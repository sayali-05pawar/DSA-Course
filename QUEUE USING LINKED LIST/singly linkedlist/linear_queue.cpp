#include <iostream>
using namespace std;

class Node
{
	public: 
	int data;
	Node *next;
	Node()
	{
		data = 0;
		next = NULL;	
	}	
};

class Queue
{
	public:
	Node *front,*rear;
	
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	
	void enque(int no)
	{
		Node *nnode;
		nnode = new Node;
		
		nnode->data = no;
		if(front == NULL && rear == NULL)
		{
			front = nnode;
			rear = nnode;
		}
		else
		{
			rear->next = nnode;
			rear = nnode;
		}
	}
	
	int deque()
	{
		int no;
		Node *x;
		
		x = front;
		no = front->data;
		front = front->next;
		
		delete x;
		return no;
	}
	
	int isempty()
	{
		if(front == NULL)
			return 1;
		else
			return 0;
	}
	
	void display()
    {
        Node *temp;
        cout<<"\nThe store numbers are: ";
        for (temp = front;temp!= NULL;temp = temp -> next)
        {
            cout<<temp -> data<<'\t';
        }
    }
};	
	
int main()
{
	Queue q;
	int choice,num;
	char ch;
	do{
		cout<<"\nMENU: "
			<<"\n1.enqueue "
			<<"\n2.dequeue "
			<<"\n3.display "
			<<"\n----------------------------";
			
		cout<<"\nEnter your choice: ";
		cin>>choice;
		
		switch (choice)
		{
			case 1: {
						cout<<"Enter a number to be insert in queue: ";
						cin>>num;
						q.enque(num);
						break;
					}
					
			case 2: {
						cout<<"\n";
						cout<<q.deque()<<" is deleted from queue";
						break;
					}
					
			case 3: q.display();
					break;
					
			default:
				cout<<"\nEnter a valid choice !!!";
		}
		cout<<"\n--------------------------------";
		cout<<"\nDo you want to repeat??? \nIf yes press 'y' else press 'n': ";
		cin>>ch;
		
	}while(ch == 'y');
	
	cout<<"\n-----------THANK YOU-----------\n";
	
	return 0;
}

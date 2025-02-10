#include <iostream>
using namespace std;


class queue
{
	int data[10];

int rear , front ;

	public:
	queue()
	{
		rear = -1;
		front = 0;	
	}
	
	void enque(int no)
	{
		if (isfull())
        {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
		rear++;
		data[rear] = no;
	}	
	
	int deque()
	{
		if (isempty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
		int n;
		n = data[front];
		front++;
		
		return n;
	}
	
	int isempty()
	{
		if(front == rear+1)
			return 1;
		else
			return 0;
	}
	
	int isfull()
	{
		if(rear == 9) //rear = size-1
			return 1;
		else 
			return 0;
	}

void display()
{
	cout<<"\nThe elements in the queue are: ";
	for(int i=front;i<=rear;i++)
		cout<<data[i]<<'\t';
}
};
int main()
{
	queue q;
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

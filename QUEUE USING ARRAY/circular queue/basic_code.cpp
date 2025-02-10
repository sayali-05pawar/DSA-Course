#include <iostream>
using namespace std;

int data[10];
int rear = -1, front = 0,counter = 0;

class queue
{
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
		rear = (rear+1) % 10; //rear = (rear+1) % size;
		data[rear] = no;
		
		counter++; //to check whether the queue is empty or full
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
		front = (front+1) % 10; //front = (front+1) % size;
		
		counter--;
		return n;
	}
	
	int isempty()
	{
		if(counter == 0)
			return 1;
		else
			return 0;
	}
	
	int isfull()
	{
		if(counter == 9) //rear = size-1
			return 1;
		else 
			return 0;
	}
};

void display()
{
    cout << "\nThe elements in the queue are: ";
    int i = front;
    int count = counter; // Store the count of elements in the queue
    while (count > 0)
    {
        cout << data[i] << '\t';
        i = (i + 1) % 10; // Wrap around to the beginning if necessary
        //i = (i+1) % size;
        count--;
    }
}

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
					
			case 3: display();
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

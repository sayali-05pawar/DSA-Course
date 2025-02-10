#include <iostream>
using namespace std;

class Queue
{
    static const int MAX_SIZE = 100; // Maximum size of the queue
    int arr[MAX_SIZE];
    int front, rear, size;

	public:
    Queue() 
    {
    	size = 0;
    	front = 0;
    	rear = -1;
	}

    // Enqueue at rear
    void enque_rear(int no)
	{
        if (size == MAX_SIZE)
		{
            cout << "Queue is full. Cannot enqueue at rear." << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = no;
        size++;
    }

    // Dequeue from front
    int deque_front()
	{
        if (isempty())
		{
            cout << "Queue is empty. Cannot dequeue from front." << endl;
            return -1; // Indicates an empty queue
        }
        int data = arr[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        return data;
    }

    // Enqueue at front
    void enque_front(int no)
	{
        if (size == MAX_SIZE)
		{
            cout << "Queue is full. Cannot enqueue at front." << endl;
            return;
        }
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;
        arr[front] = no;
        size++;
    }

    // Dequeue from rear
    int deque_rear()
	{
        if (isempty())
		{
            cout << "Queue is empty. Cannot dequeue from rear." << endl;
            return -1; // Indicates an empty queue
        }
        int data = arr[rear];
        rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
        size--;
        return data;
    }

    // Check if the Queue is empty
    bool isempty() const
	{
        return size == 0;
    }

    // Display all elements in the Queue
    void display() const
	{
        if (isempty())
		{
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << "The elements in the Queue are: ";
        int count = size;
        int i = front;
        while (count--)
		{
            cout << arr[i] << ' ';
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, num;
    char ch;

    do {
        cout << "\nMENU: "
             << "\n1. Enqueue Rear "
             << "\n2. Dequeue Front "
             << "\n3. Enqueue Front "
             << "\n4. Dequeue Rear "
             << "\n5. Display "
             << "\n----------------------------";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number to be inserted at the rear: ";
                cin >> num;
                q.enque_rear(num);
                break;

            case 2:
                cout << q.deque_front() << " is deleted from the front";
                break;

            case 3:
                cout << "Enter a number to be inserted at the front: ";
                cin >> num;
                q.enque_front(num);
                break;

            case 4:
                cout << q.deque_rear() << " is deleted from the rear";
                break;

            case 5:
                q.display();
                break;

            default:
                cout << "Enter a valid choice!";
        }
        cout << "\n--------------------------------";
        cout << "\nDo you want to repeat? (y/n): ";
        cin >> ch;

    } while (ch == 'y');

    cout << "\n-----------THANK YOU-----------\n";

    return 0;
}


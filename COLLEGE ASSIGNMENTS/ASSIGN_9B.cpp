/*Assignment No - 9(B)
 Assignment Title - Implement a checkout system for a supermarket to efficiently manage customer queues during peak hours. 
 The system should support the following operations using a circular queue data structure: 
 a. Customer arrival 
 b. Customer checkout 
 c. Close Checkout Counter 
 d. View customer.*/

 #include <iostream>
 #define MAX_SIZE 100
 using namespace std;

int counter = 0;

class customer
{
    string cus_name,contact;

    public:
    void read()
    {
        cout<<"\nEnter the customer details:- ";
        cout<<"\nCustomer Name: ";
        cin>>cus_name;
        cout<<"\nContact NO.: ";
        cin>>contact;
        cout<<"\n-------------------------------\n";
    }

    void display()
    {
        cout<<"\nCustomer Name: "<<cus_name;
        cout<<"\nContact NO.: "<<contact;
        cout<<"\n-------------------------------\n";
    }

};

class Queue
{
    int front,rear;
    customer a[MAX_SIZE];

    public:
    Queue()
    {
        front=0;
        rear=-1;
    }

    bool isempty()
    {
        if(counter == 0){
            return true;
        }
        return false;
    }

    bool isfull()
    {
        return counter == MAX_SIZE;
    }

    void enqueue(customer c)
    {
        if (isfull()) 
        {
            cout << "Queue is full. Cannot add more customers!!\n";
        } 
        else
        {
            rear = (rear + 1) % MAX_SIZE;
            a[rear] = c;
            counter++;
        }
    }

    void dequeue()
    {
        if (isempty())
        {
            cout << "Queue is empty. No customers to checkout!!\n";
        } 
        else 
        {
            cout << "\nChecking out the following customer:- ";
            a[front].display();
            front = (front + 1) % MAX_SIZE;
            counter--;
        }
    }

    void counterclosed()
    {
        rear=0;
        front=-1;
        counter=0;
        cout<<"\nCheckout counter closed.All customers have left... ";
    }

    void display()
    {
        if(isempty())  return;
        
        cout<<"Customer in the queue are: ";
        int i=front;
        int count=counter;
        while(count>0)
        {
            a[i].display();
            i=(i+1)%MAX_SIZE;
            count--;
        }
    }
};

int main() {
    Queue q; // Create a Queue object for managing customers
    int choice; // Variable to store user choice
    customer c; // Customer object for inputting details

    // Menu loop controlled by user input
    while (true) {
        cout << "\nMENU: "
             << "\n1. Customer Arrival"
             << "\n2. Customer Checkout"
             << "\n3. View Customers"
             << "\n4. Close Checkout Counter"
             << "\n5. Exit"
             << "\n-------------------------------------------";
        
        cout << "\nEnter your choice: ";
        cin >> choice; 

        switch (choice) { 
            case 1: {
                // cout << "\nEnter Customer Details:" << endl;
                c.read(); 
                q.enqueue(c); 
                break;
            }
            case 2: {
                q.dequeue(); 
                break;
            }
            case 3: {
                q.display();
                break;
            }
            case 4: {
                q.counterclosed(); 
                break;
            }
            case 5: {
                cout << "\nExiting the system. Thank you!" << endl; 
                return 0;  
            }
            default: {
                cout << "\nInvalid choice! Please select a valid option." << endl; 
            }
        }
    }

    return 0; 
}
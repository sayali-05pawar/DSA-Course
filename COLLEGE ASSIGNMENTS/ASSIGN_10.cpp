/* Assignment No - 10
 Assignment Title - Implement a job scheduling system for a manufacturing plant using a double-ended queue. 
 The system needs to efficiently manage the processing of jobs on various machines throughout the plant. Each job has a 
 Job_priority. The system should support the following operations: 
 a. Add Job 
 b. Remove Job 
 c. Display Job 
 d. Search Job*/

#include <iostream>
using namespace std;

class Node
{
    string job;
    int priority;

    public:
    Node *next,*prev;

    Node()
    {
        job=" ";
        priority=0;
        next = nullptr;
        prev = nullptr;
    }

    Node(string j,int p)
    {
        job = j;
        priority = p;
        next = nullptr;
        prev = nullptr;
    }

    int get_priority()
    {
        return priority;
    }

    void display()
    {
        cout<<"Job- "<<job<<"\tPriority- "<<priority<<endl;
    }
};

class DoublyQueue
{
    public:
    Node *front,*rear;
    doublyQueue()
    {
        front = nullptr;
        rear = nullptr;
    }

    int isempty()
    {
        return (front==nullptr && rear==nullptr);
    }

    void enqueueFront(Node &nn)
    {
        Node *nnode = new Node(nn);
        if(front==nullptr && rear==nullptr)
        {
            front = rear =nnode;
            return;
        }
        front->prev = nnode;
        nnode->next = front;
        front = nnode;
    }

    void enqueueRear(Node &nn)
    {
        Node *nnode = new Node(nn);
        if(front==nullptr && rear==nullptr)
        {
            front=rear=nnode;
        }
        rear->next=nnode;
        nnode->prev=rear;
        rear=nnode;
    }

    void dequeueFront()
    {
        if(isempty())
        {
            cout<<"Queue is empty.";
            return;
        }
        else{
            Node *temp;
            temp = front;
            front = front->next;
            delete temp;
            if(front!=nullptr)
            {
                front->prev = nullptr;
            }
            else{
                rear = nullptr;
            }
        }

    }

    void dequeueRear()
    {
        if(isempty())
        {
            cout<<"Queue is empty. ";
            return;
        }
        else{
            Node *temp;
            temp = rear;
            rear = rear->prev;
            delete temp;
            if(rear!=nullptr)
            {
                rear->next = nullptr;
            }
            else{
                front = nullptr;
            }
        }
    }

    void Display()
    {
        if(isempty())
        {
            cout<<"Queue is empty.";
            return;
        }
        Node *temp=nullptr;
        for(temp=front; temp!=nullptr; temp=temp->next)
        {
            temp->display();
        }
        cout<<endl;
    }
};

int main()
{
    DoublyQueue dq;
    int choice;
    string jobName;
    int priority;

    do {
        cout << "\n--- Job Scheduling System Menu ---\n";
        cout << "1. Add Job at Front\n";
        cout << "2. Remove Job from Front\n";
        cout << "3. Remove Job from Rear\n";
        cout << "4. Display All Jobs\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:{
            cout<<"Enter the Job name: ";
            cin>>jobName;
            cout<<"Enter it's priority: ";
            cin>>priority;

            Node newN(jobName,priority);
            if(!dq.isempty() && priority > dq.front->get_priority())
            {
                dq.enqueueFront(newN);
            }
            else
            {
                dq.enqueueRear(newN);
            }
            break;
        }
        case 2:
            dq.dequeueFront();
            cout << "Job removed from the front of the queue.\n";
            break;

        case 3:
            dq.dequeueRear();
            cout << "Job removed from the rear of the queue.\n";
            break;

        case 4:
            cout << "Displaying all jobs in the queue:\n";
            dq.Display();
            break;

        case 5:
            cout << "Exiting the Job Scheduling System. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
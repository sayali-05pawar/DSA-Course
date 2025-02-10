#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
public:
    Node *front, *rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enque(int no)
    {
        Node *nnode = new Node;
        nnode->data = no;
        nnode->next = NULL;

        if (front == NULL && rear == NULL)
        {
            front = nnode;
            rear = nnode;
            rear->next = front; // Circular link
        }
        else
        {
            nnode->next = front;
            rear->next = nnode;
            rear = nnode;
        }
    }

    int deque()
    {
        if (front == NULL)
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        int n = front->data;
        Node *temp = front;
        front = front->next;
        rear->next = front; // Update circular link

        delete temp;
        return n;
    }

    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Node *temp = front;
        cout << "\nThe elements in the queue are: ";
        do
        {
            cout << temp->data << '\t';
            temp = temp->next;
        } while (temp != front);
    }
};

int main()
{
    Queue q;
    int choice, num;
    char ch;
    do
    {
        cout << "\nMENU: "
             << "\n1.enqueue "
             << "\n2.dequeue "
             << "\n3.display "
             << "\n----------------------------";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter a number to be insert in queue: ";
            cin >> num;
            q.enque(num);
            break;
        }

        case 2:
        {
            cout << "\n";
            cout << q.deque() << " is deleted from queue";
            break;
        }

        case 3:
            q.display();
            break;

        default:
            cout << "\nEnter a valid choice !!!";
        }
        cout << "\n--------------------------------";
        cout << "\nDo you want to repeat??? \nIf yes press 'y' else press 'n': ";
        cin >> ch;

    } while (ch == 'y');

    cout << "\n-----------THANK YOU-----------\n";

    return 0;
}

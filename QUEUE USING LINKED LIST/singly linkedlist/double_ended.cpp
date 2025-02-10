#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value = 0) : data(value), next(NULL) {}
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue()
    {
    	front = NULL;
    	rear = NULL;
	}

    // Enqueue at rear
    void enque_rear(int no) {
        Node* nnode = new Node(no);
        if (rear) {
            rear->next = nnode;
        }
        rear = nnode;
        if (!front) {
            front = rear; // If the queue was empty, front and rear should point to the new node
        }
    }

    // Dequeue from front
    int deque_front() {
        if (isempty()) {
            cout << "Queue is empty. Cannot dequeue from front." << endl;
            return -1; // Indicates an empty queue
        }

        Node* temp = front;
        int data = front->data;
        front = front->next;

        if (!front) {
            rear = NULL; // If the queue is now empty, set rear to NULL
        }

        delete temp;
        return data;
    }

    // Enqueue at front
    void enque_front(int no) {
        Node* nnode = new Node(no);
        if (front) {
            nnode->next = front;
        }
        front = nnode;

        if (!rear) {
            rear = front; // If the queue was empty, front and rear should point to the new node
        }
    }

    // Dequeue from rear
    int deque_rear() {
        if (isempty()) {
            cout << "Queue is empty. Cannot dequeue from rear." << endl;
            return -1; // Indicates an empty queue
        }

        if (front == rear) { // If there's only one element
            int data = rear->data;
            delete rear;
            front = rear = NULL;
            return data;
        }

        // Find the second-to-last node
        Node* temp = front;
        while (temp->next != rear) {
            temp = temp->next;
        }
        int data = rear->data;
        delete rear;
        rear = temp;
        rear->next = NULL;
        return data;
    }

    // Check if the Queue is empty
    bool isempty() const {
        return front == NULL;
    }

    // Display all elements in the Queue
    void display() const {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "The elements in the Queue are: ";
        while (temp) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
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


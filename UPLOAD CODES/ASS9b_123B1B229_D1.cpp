/* Name - SAYALI PAWAR
 Roll no - SYCOD229
 PRN - 123B1B229
 Div - D

 Assignment No - 9(B)
 Assignment Title - Implement a checkout system for a supermarket to efficiently manage customer queues during peak hours. 
 The system should support the following operations using a circular queue data structure: 
 a. Customer arrival 
 b. Customer checkout 
 c. Close Checkout Counter 
 d. View customer.*/

#include <iostream>
#define MAX_SIZE 100 // Define maximum size of the queue
using namespace std;

int counter = 0; // Global counter to track the number of customers in the queue

// Customer Class
class Customer {
    string customer_name; // Customer's name
    string contact; // Customer's contact number

public:
    // Function to take customer details
    void read() {
        cout << "Enter the Customer Name: ";
        cin >> customer_name; 
        cout << "Enter the Customer's Contact Number (10 digits): ";
        cin >> contact;
    }

    // Function to display customer details
    void display() {
        cout << "Customer Name: " << customer_name << endl; 
        cout << "Customer Contact No: " << contact << endl;
        cout << "-------------------------------------------" << endl; 
    }
};

// Queue class implementing circular queue
class Queue {
    Customer queue[MAX_SIZE]; // Array of Customer objects to represent the queue
    int rear, front; 

public:
    // Constructor to initialize the queue
    Queue() {
        rear = -1; // Initialize rear to -1, indicating the queue is empty
        front = 0; // Initialize front to 0
    }

    // Function to add a customer to the queue (Customer Arrival)
    void enqueue(Customer c) {
        
        if (isFull()) {
            cout << "Queue is full. Cannot add more customers." << endl;
            return; // Exit function if queue is full
        }

        rear = (rear + 1) % MAX_SIZE; // Update rear index in a circular manner
        queue[rear] = c; // Add customer object to the queue
        counter++;  // Increment counter to check fullness
    }

    // Function to remove a customer from the queue (Customer Checkout)
    void dequeue() {
        
        if (isEmpty()) {
            cout << "Queue is empty. No customer to checkout." << endl;
            return; // Exit function if queue is empty
        }

        cout << "Checking out the following customer:" << endl;
        queue[front].display(); // Display customer details being checked out
        front = (front + 1) % MAX_SIZE; // Update front index in a circular manner
        counter--;  // Decrement counter to track the queue size
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        if (counter == 0) { // If counter is 0, queue is empty
            closeCounter();  // Close the counter if the queue is empty
            return true; // Return true for empty queue
        }
        return false; // Return false if queue is not empty
    }

    // Function to check if the queue is full
    bool isFull() {
        return (counter == MAX_SIZE); // Returns true if the queue is full (MAX_SIZE)
    }

    // Function to view all customers in the queue
    void display() {
        // Check if the queue is empty
        if (isEmpty()) {
            return; // Exit function if queue is empty
        }
        cout << "Customers in the queue:" << endl; // Notify users about the queue status
        int i = front; // Start from the front of the queue
        int count = counter; // Keep track of the number of customers to display
        while (count > 0) {
            queue[i].display(); // Display each customer's details
            i = (i + 1) % MAX_SIZE; // Move to the next customer in a circular manner
            count--; // Decrement count
        }
    }

    // Function to close the checkout counter
    void closeCounter() {
        rear = -1; // Reset rear to -1
        front = 0; // Reset front to 0
        counter = 0; // Reset counter to 0
        cout << "Checkout counter closed. All customers have left." << endl; // Notify closure
    }
};

int main() {
    Queue q; // Create a Queue object for managing customers
    int choice; // Variable to store user choice
    Customer c; // Customer object for inputting details

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
                cout << "\nEnter Customer Details:" << endl;
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
                q.closeCounter(); 
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

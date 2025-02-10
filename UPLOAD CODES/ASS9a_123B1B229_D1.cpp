/* Name - SAYALI PAWAR
 Roll no - SYCOD229
 PRN - 123B1B229
 Div - D

 Assignment No - 9(A)
 Assignment Title - Implement a restaurant waitlist system using the queue data structure. 
 Restaurant waitlist provide following facility: 
 a. Add Party to Waitlist 
 b. Seat Party 
 c. Display Waitlist*/

#include <iostream>
#include <string>
using namespace std;

// Queue class representing a waitlist for parties
class Queue
{
    string data[10]; // Array to store party names
    int rear, front; // Indices for the rear and front of the queue

public:
    // Constructor to initialize the queue
    Queue()
    {
        rear = -1; // Initialize rear to -1, indicating the queue is empty
        front = 0; // Initialize front to 0
    }

    // Function to add a party to the waitlist
    void enqueue(string partyName)
    {
        // Check if the queue is full
        if (isFull())
        {
            cout << "Waitlist is full. Cannot add more parties." << endl;
            return;
        }
        rear++; // Move rear to the next position
        data[rear] = partyName; // Add party name to the queue
        cout << "Added " << partyName << " to the waitlist." << endl;
    }

    // Function to seat a party (remove from the waitlist)
    string dequeue()
    {
        // Check if the queue is empty
        if (isEmpty())
        {
            cout << "Waitlist is empty. No parties to seat." << endl;
            return ""; // Return an empty string
        }
        string partyName = data[front]; // Get the party name at the front
        front++; // Move front to the next position
        return partyName; // Return the seated party name
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == rear + 1; // Returns true if there are no parties in the waitlist
    }

    // Function to check if the queue is full
    bool isFull()
    {
        return rear == 9; // Returns true if the queue is full (10 elements max)
    }

    // Function to display the current waitlist
    void display()
    {
        // Check if the queue is empty
        if (isEmpty())
        {
            cout << "Waitlist is empty." << endl;
            return;
        }

        // Display the waitlist
        cout << "The current waitlist is: ";
        for (int i = front; i <= rear; i++)
            cout << data[i] << '\t'; 
        cout << endl;
    }
};

int main()
{
    Queue waitlist; 
    int choice; 
    string Name; 
    char ch; 
   
    while (1)
    {
       
        cout << "\nMENU: "
             << "\n1. Add Party to Waitlist"
             << "\n2. Seat Party"
             << "\n3. Display Waitlist"
             << "\n4. Exit"
             << "\n----------------------------";

        cout << "\nEnter your choice: ";
        cin >> choice; 

        switch (choice) 
        {
        case 1:
           
            cout << "Enter the Name to add to the waitlist: ";
            cin >> Name; 
            waitlist.enqueue(Name); 
            break;

        case 2:
        {
            
            string seatedParty = waitlist.dequeue(); 
            if (!seatedParty.empty()) 
                cout << seatedParty << " has been seated." << endl;
            break;
        }

        case 3:
            waitlist.display(); 
            break;

        case 4:
            cout << "\n-----------THANK YOU-----------\n";
            exit(0); 

        default:
            cout << "Enter a valid choice!" << endl; 
        }
    }

    return 0;
}
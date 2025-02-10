/* Name - SAYALI PAWAR
 Roll no - SYCOD229
 PRN - 123B1B229
 Div - D

 Assignment No - 7
 Assignment Title - Implement a browser history management system using a stack data structure to track the user's browsing 
 history. The system should support the following functionalities: 
 a. Add visited page 
 b. Navigate back 
 c. View current page 
 d. Check if history is empty or not Assume no upper bound on number of pages visited.*/


#include <iostream>
using namespace std;

// Node class to represent each page in the browsing history
class Node
{
public:
    string Address; // URL of the visited page
    Node *next; // Pointer to the next Node in the stack

    // Default constructor initializing next to NULL
    Node() { next = NULL; }

    // Parameterized constructor to initialize the address
    Node(string s)
    {
        Address = s; // Set the Address to the provided URL
        next = NULL; // Initialize next to NULL
    }

    // Method to display the current address
    void DisplayAddress()
    {
        cout << "Address: " << Address << endl;
    }
};

// BrowserHistoryStack class to manage the history using a stack structure
class BrowserHistoryStack
{
public:
    Node *Top; // Pointer to the top Node of the stack

    // Constructor initializing the Top to NULL
    BrowserHistoryStack() { Top = NULL; }

    // Check if the history stack is empty
    bool isEmpty()
    {
        return Top == nullptr; // Returns true if Top is NULL
    }

    // Push function to add a new page to the history stack
    void NewPage(string s)
    {
        Node *nn = new Node(s); // Create a new Node with the URL
        if (isEmpty()) // If the stack is empty
        {
            Top = nn; // Set Top to the new Node
        }
        else // If there are already pages in the history
        {
            nn->next = Top; // Link the new Node to the current Top
            Top = nn; // Update Top to the new Node
        }
    }

    // Pop function to navigate back to the previous page
    void NavigateBack()
    {
        if (isEmpty()) // Check if the stack is empty
        {
            cout << "No pages in history!" << endl; // Notify user if empty
        }
        else
        {
            Node *Temp = Top; // Store the current top Node
            Top = Top->next; // Move Top to the next Node
            delete Temp; // Delete the old top Node
        }
    }

    // Peek function to show the current page
    void ShowCurrentPage()
    {
        if (isEmpty()) // Check if the stack is empty
        {
            cout << "No pages in history!" << endl; // Notify user if empty
        }
        else
        {
            Top->DisplayAddress(); // Display the address of the current top Node
        }
    }
};

int main()
{
    BrowserHistoryStack browserHistory; // Create an instance of BrowserHistoryStack
    int choice; // Variable to store user's menu choice
    string url; // Variable to store the URL of the page to visit

    // Infinite loop for the menu
    while (1)
    {
        // Display menu options
        cout << "\nBrowser History Menu: " << endl
             << "1. Visit new page" << endl
             << "2. Go back" << endl
             << "3. Show current page" << endl
             << "4. Check History Empty or not" << endl
             << "5. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: 
            cout << "Enter the URL of the new page: ";
            cin >> url; // Get the URL from the user
            browserHistory.NewPage(url); // Add the new page to history
            cout << "Navigated to " << url << endl; 
            break;

        case 2: // Navigate back
            browserHistory.NavigateBack(); 
            cout << "Navigated back to previous page." << endl;
            break;

        case 3: // Show current page
            browserHistory.ShowCurrentPage(); 
            break;

        case 4: // Check if history is empty
            if (browserHistory.isEmpty()) 
            {
                cout << "No pages in history!" << endl; // Notify user if empty
            }
            else
            {
                cout << "History is not Empty." << endl; // Confirm history is present
            }
            break;

        case 5: // Exit program
            cout << "Exiting..." << endl;
            exit(0); 

        default: 
            cout << "Invalid choice! Please try again." << endl; 
            break;
        }
    }

    return 0; 
}
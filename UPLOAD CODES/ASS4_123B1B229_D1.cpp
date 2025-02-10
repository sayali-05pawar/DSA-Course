/* Name - SAYALI PAWAR
 Roll no - SYCOD229
 PRN - 123B1B229
 Div - D

 Assignment No - 4
 Assignment Title - Implement a simple text editor application using a doubly linked list to manage the text buffer.
 Text editor should support the following functionalities: 
 a. Insert text 
 b. Delete text 
 c. Display text 
 d. Search text 
 e. Print text in reverse.*/

#include <iostream>
#include <string>
using namespace std;

class Node
{
    public: 
    string data;  // Stores text data
    Node *next, *prev;  // Pointers to next and previous nodes in the doubly linked list
    Node()
    {
        next = NULL;
        prev = NULL;    
    }   
};

class text_editor
{
    Node *start;  // Pointer to the start of the doubly linked list
    public:
    text_editor()
    {
        start = NULL;   
    }

    // Function to create and insert text into the doubly linked list
    void create()  
    {
        Node *nnode;  
        Node *temp;    
        char ch;       
        do {
            nnode = new Node;  // Create a new node
            cout << "Enter the text to be stored: ";  
            cin >> nnode->data;  // Store user input in the node
            
            if (start == NULL)  // If list is empty, make the new node the start node
            {
                start = nnode;  
            }
            else 
            {
                // Traverse to the end of the list and insert the new node
                for (temp = start; temp->next != NULL; temp = temp->next);
                temp->next = nnode;
                nnode->prev = temp;
            }
            cout << "Do you have more data (y/n): ";
            cin >> ch;  
        } while (ch == 'y');  // Continue inserting while user chooses 'y'
    }

    // Function to display the text stored in the list
    void display()
    {
        Node *temp;
        cout << "\nThe stored text is: ";
        for (temp = start; temp != NULL; temp = temp->next)
        {
            cout << temp->data << '\t';  // Print the text in each node
        }
    }

    // Function to display the text in reverse order
    void dis_rev()
    {
        Node *temp;
        cout << "\nReversing the text: ";
        // Traverse to the last node
        for (temp = start; temp->next != NULL; temp = temp->next);
        // Print the text in reverse order by moving backwards through the list
        for (; temp != NULL; temp = temp->prev)
            cout << temp->data << '\t';
    }

    // Function to insert a new node at the beginning of the list
    void ins_beg()
    {
        Node *nnode, *temp;
        nnode = new Node;  // Create a new node
        cout << "Enter a text to be inserted at the beginning: ";
        cin >> nnode->data;  // Store user input in the node
        
        nnode->next = start;  // New node points to the current start node
        start->prev = nnode;  // Set previous pointer of the start node to new node
        start = nnode;  // Update start pointer to the new node
        
        display();  // Display updated list
    
    }

    // Function to insert a new node between any two nodes in the list
    void ins_between()
    {
        Node *nnode, *temp;
        string n;
        nnode = new Node;  // Create a new node
        cout << "\nEnter a text to be inserted: ";
        cin >> nnode->data;  // Store user input in the node
        
        cout << "Enter the text after which you want to insert: ";
        cin >> n;
        // Traverse to find the node after which the new node should be inserted
        for (temp = start; temp != NULL; temp = temp->next)
        {
            if (temp->data == n)  // Match found
            {
                nnode->next = temp->next;  // New node points to the next node
                temp->next = nnode;  // Current node points to the new node
                nnode->prev = temp;  // Set previous pointer of new node to current node
                if (nnode->next != NULL)  // If not inserting at the end
                    nnode->next->prev = nnode;  // Set previous pointer of next node to new node
                break;
            }
        }

        display();  // Display updated list
    }

    // Function to insert a new node at the end of the list
    void ins_end()
    {
        Node *nnode, *temp;
        nnode = new Node;  // Create a new node
        cout << "\nEnter a text to be inserted at end: ";
        cin >> nnode->data;  // Store user input in the node

        // Traverse to the last node
        for (temp = start; temp->next != NULL; temp = temp->next);
        temp->next = nnode;  // Last node points to the new node
        nnode->prev = temp;  // New node points back to the last node

        display();  // Display updated list
    }

    // Function to delete the node at the beginning of the list
    void del_beg()
    {
        Node *x;
        x = start;  // Point to the current start node
        start = start->next;  // Move start pointer to the next node
        if (start != NULL)
            start->prev = NULL;  // Set the previous pointer of the new start to NULL
        delete x;  // Delete the old start node

        display();  // Display updated list
    }

    // Function to delete a node between any two nodes in the list
    void del_between() 
    {
        Node *x, *temp;
        string search;
        cout << "Enter the text you want to delete: ";
        cin >> search;
        
        // Traverse to find the node to be deleted
        for (temp = start; temp != NULL; temp = temp->next)
        {
            if (temp->data == search)  // Match found
            {
                x = temp;  // Point to the node to be deleted
                temp->prev->next = temp->next;  // Adjust the next pointer of the previous node
                if (temp->next != NULL)  // If not deleting the last node
                    temp->next->prev = temp->prev;  // Adjust the previous pointer of the next node
                delete x;  // Delete the node
                break;
            }
        }

        display();  // Display updated list
    }

    // Function to delete the node at the end of the list
    void del_end()
    {
        Node *x, *temp;
        // Traverse to the second-last node
        for (temp = start; temp->next->next != NULL; temp = temp->next);
        x = temp->next;  // Point to the last node
        temp->next = NULL;  // Set next pointer of second-last node to NULL
        delete x;  // Delete the last node

        display();  // Display updated list
    }

    // Function to search for text in the list
    void issearch()
    {
        int found = 0;
        string n;
        Node *temp;
        cout << "\nEnter the text to be searched: ";
        cin >> n;

        // Traverse to search for the text
        for (temp = start; temp != NULL; temp = temp->next)
        {
            if (temp->data == n)  // Match found
            {   
                found = 1;  // Mark as found
                break;
            }
        }

        if (found == 1)
            cout << "Text is found!!";
        else
            cout << "Text is not found!";
    }

};

int main()
{
    text_editor l;
    int choice;
    char ch;
    while (1)
    {
        cout<<"\nMENU: "
            <<"\n1.Store text"
            <<"\n2.Display text"
            <<"\n3.Display reverse text"
            <<"\n4.Insert text at beginning"
            <<"\n5.Insert text in between any position "
            <<"\n6.Insert text at end"
            <<"\n7.Delete text of beginning"
            <<"\n8.Delete text of an position in between"
            <<"\n9.Delete text of end"
            <<"\n10.Search text"
            <<"\n11.Exit"
            <<"\n------------------------------------------------";
            
        cout<<"\nEnter your choice: ";
        cin>>choice;    

        switch (choice) {
            case 1: 
                l.create();
                break;
            case 2: 
                l.display();
                break;
            case 3: 
                l.dis_rev();
                break;
            case 4: 
                l.ins_beg();
                break;
            case 5: 
                l.ins_between();
                break;
            case 6: 
                l.ins_end();
                break;
            case 7: 
                l.del_beg();
                break;
            case 8: 
                l.del_between();
                break;
            case 9: 
                l.del_end();
                break;
            case 10:
                l.issearch();
                break;
            case 11:
                cout<<"\n\n-------------THANK YOU-------------\n\n";
                exit(0);
            default:
                cout << "\nInvalid choice! Please enter a valid choice !!!!! ";
                break;
            }
    }
    return 0;
}
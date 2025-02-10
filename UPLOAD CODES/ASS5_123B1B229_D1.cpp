/* Name - SAYALI PAWAR
 Roll no - SYCOD229
 PRN - 123B1B229
 Div - D

 Assignment No - 5
 Assignment Title - Implement a navigation system for a delivery service using a circular linked list to represent routes. 
 The navigation system should support the following functionalities: 
 a. Add route 
 b. Remove route 
 c. Display route.*/

 #include <iostream>
using namespace std;

// Node class represents a single route in the circular linked list
class Node
{
    public:
    Node *next; // Pointer to the next node
    string sou, des; // Source 1and destination addresses
    float time, distance, charges; // Time, distance, and travel charges

    Node()
    {
        next = NULL; 
    }

    // Function to read route details from user input
    void read();

    // Function to display route details
    void display_nav();

    // Function to return the source address of the route
    string get_source();

    // Function to modify route details
    void newd(string a, string b, float c, float d, float e);
};

void Node::read()
{
    cout << "\nEnter the SOURCE Address: ";
    cin >> sou;
    cout << "\nEnter the DESTINATION Address: ";
    cin >> des;
    cout << "\nEnter the Distance Between source and destination in km: ";
    cin >> distance;
    cout << "\nTime required in minutes: ";
    cin >> time;
    cout << "\nCharges for Travelling: ";
    cin >> charges;
}

void Node::display_nav()
{
    cout << "\nSOURCE: " << sou;
    cout << "\nDESTINATION: " << des;
    cout << "\nDistance from " << sou << " to " << des << " is " << distance << " km.";
    cout << "\n" << time << " minutes are required to reach!!!";
    cout << "\nCharges: " << charges << " RS.";
    cout << "\n----------------------------------------------\n";
}

string Node::get_source()
{
    return sou;
}

void Node::newd(string a, string b, float c, float d, float e)
{
    sou = a;
    des = b;
    distance = c;
    time = d;
    charges = e;
}

//--------------------------------------------------------------------------------------------------------------------

// Navigation class represents a circular linked list of routes
class navigation
{
    Node *start; // Pointer to the first node in the circular linked list

    public:
    navigation()
    {
        start = NULL; 
    }

    // Function to create the circular linked list by adding routes
    void create();

    // Function to display all routes
    void display();

    // Function to insert a route at the beginning
    void ins_beg();

    // Function to insert a route between two routes
    void ins_between();

    // Function to insert a route at the end
    void ins_end();

    // Function to remove the first route from the list
    void del_beg();

    // Function to remove a route in between
    void del_between();

    // Function to remove the last route from the list
    void del_end();

    // Function to modify route details
    void modify();
};

void navigation::create()
{
    Node *nnode; 
    Node *temp; 
    char ch; 

    do {
        nnode = new Node; 
        cout << "\nEnter details:- : ";
        nnode->read(); // Read route details

        if (start == NULL) // If the list is empty, set start to the new node
        {
            start = nnode;
            nnode->next = start; // Make the list circular by pointing back to the start
        }
        else
        {
            temp = start;
            while (temp->next != start) {
                temp = temp->next; // Traverse to the last node
            }
            temp->next = nnode; // Insert new node at the end
            nnode->next = start; // Make the list circular
        }

        cout << "\nDo you have more data?? (y/n): ";
        cin >> ch;  
    } while (ch == 'y'); // Continue adding nodes if the user inputs 'y'
}

void navigation::display()
{
    Node *temp = start; 
    cout << "\nThe stored Details are: ";
    do {
        temp->display_nav(); 
        temp = temp->next; // Move to the next route
    } while (temp != start); // Stop when we reach the first route again (circular list)
}

void navigation::ins_beg()
{
    Node *nnode, *temp;

    nnode = new Node;
    cout << "Enter a Source address to be ADD at begin:- ";
    nnode->read(); // Read route details

    if (start == NULL) // If the list is empty
    {
        start = nnode; // Set the new node as the start
        nnode->next = start; // Make the list circular
    }
    else
    {
        for (temp = start; temp->next != start; temp = temp->next);
        nnode->next = start; // Insert new node at the beginning
        start = nnode; // Update start to the new node
        temp->next = start; // Maintain circular structure
    }
    display();
}

void navigation::ins_between()
{
    Node *nnode, *temp;
    string n;

    nnode = new Node; // Allocate memory for a new node
    cout << "\nEnter a Source address to be ADD:- ";
    nnode->read(); // Read route details

    cout << "Enter the Source address after which you want to ADD:- ";
    cin >> n;

    for (temp = start; temp != start; temp = temp->next)
    {
        if (temp->get_source() == n) // Check if we found the source
        {
            nnode->next = temp->next; // Insert new node after temp
            temp->next = nnode;
            break;
        }
    }

    display();
}

void navigation::ins_end()
{
    Node *nnode, *temp;

    nnode = new Node; // Allocate memory for a new node
    cout << "\nEnter a Source address to be ADDed at end:- ";
    nnode->read(); // Read route details

    if (start == NULL) // If the list is empty
    {
        start = nnode; // Set the new node as the start
        nnode->next = start; // Make the list circular
    }
    else
    {
        for (temp = start; temp->next != start; temp = temp->next);
        temp->next = nnode; // Insert new node at the end
        nnode->next = start; // Maintain circular structure
    }
    display();
}

void navigation::del_beg()
{
    Node *temp;
    Node *x = start;

    for (temp = start; temp->next != start; temp = temp->next); // Traverse to the last node

    if (temp == start) // If there is only one route
    {
        start = NULL; // Empty the list
        cout << "\nThere is no data in linked list !!";
    }
    else
    {
        start = start->next; // Update start to the next route
        temp->next = start; // Maintain circular structure
        display();
    }
    delete x; // Delete the old start node
}

void navigation::del_between()
{
    Node *x, *temp = start;
    string num;

    cout << "Enter the Source address which you want to remove:- ";
    cin >> num;

    for (temp = start; temp != start; temp = temp->next)
    {
        if (temp->next->get_source() == num) // Check if the next node has the matching source
        {
            x = temp->next; // Store the next node in x
            temp->next = x->next; // Remove x from the list
            delete x; // Delete the removed node
            break;
        }
    }

    display();
}

void navigation::del_end()
{
    Node *x, *temp;

    if (start == NULL) // If the list is empty
    {
        cout << "\nList is empty. Cannot remove from an empty list !!!";
    }
    else
    {
        for (temp = start; temp->next->next != start; temp = temp->next); // Traverse to the second last node
        x = temp->next; // Store the last node in x
        temp->next = start; // Remove the last node and maintain circular structure
        delete x; // Delete the last node
        display();
    }
}

void navigation::modify()
{
    int found = 0;
    Node *temp;
    string nsou, ndes, n;
    float nt, ndist, ncha;

    cout << "\nEnter the Source address which you want to Modify:- ";
    cin >> n;

    cout << "Enter the new source address: ";
    cin >> nsou;
    cout << "Enter the new destination address: ";
    cin >> ndes;
    cout << "\nEnter the Distance Between source and destination in km: ";
    cin >> ndist;
    cout << "\nTime required in minutes: ";
    cin >> nt;
    cout << "\nCharges for Travelling: ";
    cin >> ncha;

    for (temp = start; temp != NULL; temp = temp->next)
    {
        if (temp->get_source() == n) // Check if the source matches
        {
            temp->newd(nsou, ndes, ndist, nt, ncha); // Modify the route details
            found = 1;
            break;
        }
    }

    if (found == 1)
        cout << "The Route is MODIFIED !!!!";
    else
        cout << "Route not MODIFIED ";
}

int main()
{
    navigation l;
    int choice;

    while (1)
    {
        cout << "\nMENU: "
             << "\n1.Store data"
             << "\n2.Display data"
             << "\n3.ADD ROUTE data at beginning"
             << "\n4.ADD ROUTE data in between any position"
             << "\n5.ADD ROUTE data at end"
             << "\n6.REMOVE ROUTE data of beginning"
             << "\n7.REMOVE ROUTE data of an position in between"
             << "\n8.REMOVE ROUTE data of end"
             << "\n9.MODIFIY Details"
             << "\n10.Exit"
             << "\n------------------------------------------------";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            l.create();
            break;
        case 2:
            l.display();
            break;
        case 3:
            l.ins_beg();
            break;
        case 4:
            l.ins_between();
            break;
        case 5:
            l.ins_end();
            break;
        case 6:
            l.del_beg();
            break;
        case 7:
            l.del_between();
            break;
        case 8:
            l.del_end();
            break;
        case 9:
            l.modify();
            break;
        case 10:
            cout << "\n\n-------------THANK YOU-------------\n\n";
            exit(0);
        default:
            cout << "\nInvalid choice! Please enter a valid choice !!!!! ";
            break;
        }
        cout << "\n----------------------------------------------";
    }
    return 0;
}



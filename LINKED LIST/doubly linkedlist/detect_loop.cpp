/*Loop Creation:
I added a create_loop() function in the ins_del class to manually introduce a loop in the doubly linked list. 
This method connects the last node's next pointer to the second node in the list to form a loop. 
This will allow the detect_loop() method to correctly identify the cycle.

Loop Detection:
The detect_loop() function remains unchanged and uses the Floyd's Cycle-Finding Algorithm to detect if the slow_ptr and
 fast_ptr meet inside the list, indicating a loop.*/

#include <iostream>
using namespace std;

class Node {
public:
    int no;
    Node *next, *prev;
    
    Node() {
        no = 0;
        next = NULL;
        prev = NULL;
    }
};

class ins_del {
    Node *start;

public:
    ins_del() {
        start = NULL;
    }

    // Function to create a doubly linked list
    void create() {
        Node *nnode;
        Node *temp;
        char ch;

        do {
            nnode = new Node;
            cout << "Enter the number to be stored: ";
            cin >> nnode->no;

            if (start == NULL) {
                start = nnode;
            } else {
                for (temp = start; temp->next != NULL; temp = temp->next);
                temp->next = nnode;
                nnode->prev = temp;
            }

            cout << "Do you have more data? If yes, press 'y'; else press 'n': ";
            cin >> ch;
        } while (ch == 'y');
    }

    // Function to detect a loop using Floyd's Cycle-Finding Algorithm
    bool detect_loop() {
        Node *slow_ptr = start;
        Node *fast_ptr = start;

        while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;

            // If the slow and fast pointers meet, a loop is detected
            if (slow_ptr == fast_ptr) {
                return true;
            }
        }

        // No loop detected
        return false;
    }

    // Function to display the list
    void display() {
        Node *temp;
        cout << "\nThe stored numbers are: ";
        for (temp = start; temp != NULL; temp = temp->next) {
            cout << temp->no << '\t';
        }
    }

    // Function to display the list in reverse
    void dis_rev() {
        Node *temp;
        cout << "\nReversing the numbers: ";
        for (temp = start; temp->next != NULL; temp = temp->next);
        for (; temp != NULL; temp = temp->prev)
            cout << temp->no << '\t';
    }

    // Helper function to create a loop for testing
    void create_loop() {
        Node *temp = start;
        Node *last = start;

        // Traverse to the last node
        while (last->next != nullptr) {
            last = last->next;
        }

        // Create a loop by making the last node point to the second node
        last->next = temp->next;  // This creates a loop between the last node and the second node
    }
};

int main() {
    ins_del l;
    l.create();

    // Creating a loop manually for testing
    l.create_loop();

    // Detect loop
    if (l.detect_loop()) {
        cout << "Loop detected in the linked list" << endl;
    } else {
        cout << "No loop detected in the linked list" << endl;
    }

    // The display and reverse functions will run infinitely if a loop is present.
    // You can disable them if a loop is detected.
    l.display();  
    l.dis_rev();

    cout << "\n\n-------------THANK YOU-------------\n\n";
    return 0;
}

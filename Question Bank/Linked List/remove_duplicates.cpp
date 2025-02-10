/*Describe how you would remove duplicate elements from a singly linked list.*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;     
    Node* next;   

    Node()
    {
        data = 0;
        next = nullptr;
    }
};

class LinkedList {
    Node* start; 

public:
    LinkedList() : start(nullptr) {}

    
    void create() {
        Node* nnode;  
        Node* temp;   

        cout << "Enter numbers to store in the list (enter -1 to stop): ";
        while (true) {
            nnode = new Node(); 
            cin >> nnode->data;

            if (nnode->data == -1) { // Stop condition
                delete nnode;       // Free unused node memory
                break;
            }

            nnode->next = nullptr; // Initialize the next pointer of the new node

            if (start == nullptr) { // If the list is empty
                start = nnode;      // Set the new node as the first node
            } else {
                temp = start;
                while (temp->next != nullptr) { // Traverse to the end of the list
                    temp = temp->next;
                }
                temp->next = nnode; // Append the new node at the end
            }
        }
    }

    
    void display() {
        if (start == nullptr) {
            cout << "\nThe list is empty!" << endl;
            return;
        }

        Node* temp = start;
        cout << "\nThe stored numbers are: ";
        while (temp != nullptr) {
            cout << temp->data << '\t';
            temp = temp->next;
        }
        cout << endl;
    }

   
    Node* getHead() {
        return start;
    }

    void removeDuplicates() 
    {
        if (start == nullptr) return;

        Node* current = start;

        // Traverse the list with the outer for loop
        for (; current != nullptr; current = current->next) {
            Node* runner = current->next; // The runner starts from the node after current

            // Check the subsequent nodes using the runner
            for (; runner != nullptr; runner = runner->next) {
                if (current->data == runner->data) {
                    // Duplicate found, remove the runner node
                    Node* temp = runner;
                    runner = runner->next; // Move runner to the next node
                    current->next = runner; // Link the current node to the next node of runner
                    delete temp; // Free the memory
                }
            }
        }
    }

};



int main() {
    LinkedList list;

    // Create the linked list
    list.create();

    // Display the linked list
    list.display();

    list.removeDuplicates();
    list.display();
    

    return 0;
}

/*Write an algorithm for detecting cycle in a singly linked list.*/
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
};

// Function to detect a cycle in the linked list
bool detect_cycle(Node* head) {
    if (head == nullptr) return false;

    Node* slow = head;  // Slow pointer
    Node* fast = head;  // Fast pointer

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         // Move slow pointer by 1 step
        fast = fast->next->next;   // Move fast pointer by 2 steps

        if (slow == fast) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle
}

int main() {
    LinkedList list;

    // Create the linked list
    list.create();

    // Display the linked list
    list.display();

    // Get the head of the list
    Node* head = list.getHead();

    // Introduce a cycle for testing (manually linking the last node to a previous node)
    if (head != nullptr && head->next != nullptr && head->next->next != nullptr) {
        Node* temp = head;
        while (temp->next != nullptr) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = head->next; // Create a cycle
    }

    // Check for a cycle in the linked list
    if (detect_cycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    return 0;
}

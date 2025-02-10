/*Remove duplicates from a unsorted linked list*/

#include <iostream>
using namespace std;

// Node structure definition
class Node {
public:
    int data;      // Data stored in the node
    Node* next;    // Pointer to the next node

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class definition
class LinkedList {
    Node* head;   // Pointer to the first node

public:
    // Constructor to initialize the linked list
    LinkedList() {
        head = nullptr;
    }

    // Function to create the linked list from user input
    void create() {
        Node* newNode;
        Node* temp;
        char choice;

        do {
            int value;
            cout << "Enter the number to be stored: ";
            cin >> value;
            newNode = new Node(value);

            if (head == nullptr) {
                head = newNode;
            } else {
                temp = head;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = newNode;
            }

            cout << "Do you have more data (y/n)? : ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }

    // Function to remove duplicates from the unsorted linked list
    void removeDuplicates() {
        Node* ptr1 = head;
        Node* ptr2 = nullptr;
        Node* dup = nullptr;

        // Pick elements one by one and compare with all other elements
        while (ptr1 != nullptr && ptr1->next != nullptr) {
            ptr2 = ptr1;
            while (ptr2->next != nullptr) {
                if (ptr1->data == ptr2->next->data) {
                    dup = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    delete dup;
                } else {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        cout << "The stored numbers are: ";
        while (temp != nullptr) {
            cout << temp->data << '\t';
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Create the linked list from user input
    list.create();

    // Display the original list
    list.display();

    // Remove duplicates from the list
    list.removeDuplicates();

    // Display the list after removing duplicates
    list.display();

    return 0;
}

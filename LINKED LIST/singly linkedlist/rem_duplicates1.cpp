/*Remove duplicates from a sorted linked list*/

#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;      // Data stored in the node
    Node* next;    // Pointer to the next node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;   // Pointer to the first node

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to create the linked list
    void create() {
        Node* newNode;
        Node* temp;
        char choice;

        do {
            int value;
            cout << "Enter the number for sorted linkedlist: ";
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

    // Function to remove duplicates from a sorted linked list
    void removeDuplicates() {
        if (head == nullptr || head->next == nullptr)
            return;

        Node* current = head;
        while (current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* duplicateNode = current->next;
                current->next = current->next->next;
                delete duplicateNode;
            } else {
                current = current->next;
            }
        }
    }


    // Function to display the linked list
    void display() {
        Node* temp = head;
        cout << "\nThe stored numbers are: ";
        while (temp != nullptr) {
            cout << temp->data << '\t';
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Create the linked list
    list.create();

    // Display the original list
    list.display();

    // Remove duplicates from the list
    list.removeDuplicates();

    // Display the list after removing duplicates
    list.display();


    return 0;
}

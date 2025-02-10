/*Given a singly linked list, write a function to find the middle element of the list.*/
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

    void findmiddle()
    {
        if(start == nullptr) return;

        Node *slow = start;
        Node *fast = start;

        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        cout<<"\nThe middle element is: "<<slow->data;
    }
};


int main() {
    LinkedList list;

    // Create the linked list
    list.create();

    // Display the linked list
    list.display();

    // Get the head of the list
    Node* head = list.getHead();

    list.findmiddle();

    return 0;
}

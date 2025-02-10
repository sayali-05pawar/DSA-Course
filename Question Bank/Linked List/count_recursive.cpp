/*Suppose, you are developing a contact managementsystem that stores contacts in a linked list. Each contact entry in the list 
includes details such as name, phone number, and email address, and each contact node points to the next contact in the list.
Find the total number of contacts in your list using a recursive method.*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;     
    Node* next,*prev;   

    Node()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
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

int count(Node *start)
    {
       if(start)
       {
            return 1+count(start->next);
       }
       return 0;
    }

int main() {
    LinkedList l1;

    // Create the first linked list
    cout << "Create the first sorted linked list:\n";
    l1.create();

   cout<<"The count of linkedlist: "<<count(l1.getHead());


    return 0;
}


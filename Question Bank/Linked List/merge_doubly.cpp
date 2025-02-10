/*Write a function to merge two sorted doubly linked lists.*/
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

Node *merge_doubly(Node *head1,Node *head2)
    {
        if(!head1) return head2;
        if(!head2) return head1;

        Node* mergehead = nullptr;

        if(head1->data < head2->data)
        {
            mergehead = head1;
            head1 = head1->next;
        }else{
            mergehead = head2;
            head2 = head2->next;
        }

        mergehead->prev=nullptr;
        Node *current = mergehead;
        while(head1 && head2)
        {
            if(head1->data<head2->data)
            {
                current->next = head1;
                head1->prev = current;
                head1 = head1->next;
                current = current->next;
            }
            else{
                current->next = head2;
                head2->prev = current;
                head2 = head2->next;
                current = current->next;
            }
        }

        if (head1) {
        current->next = head1;
        head1->prev = current;
    } else if (head2) {
        current->next = head2;
        head2->prev = current;
    }

        return mergehead;
    }

int main() {
    LinkedList l1, l2;

    // Create the first linked list
    cout << "Create the first sorted linked list:\n";
    l1.create();

    // Create the second linked list
    cout << "Create the second sorted linked list:\n";
    l2.create();

    // Merge the two sorted linked lists
    Node* mergedHead = merge_doubly(l1.getHead(), l2.getHead());

    // Display the merged linked list
    if (mergedHead == nullptr) {
        cout << "The merged list is empty!" << endl;
    } else {
        cout << "The merged sorted linked list is:\n";
        Node* temp = mergedHead;
        while (temp != nullptr) {
            cout << temp->data << '\t';
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}


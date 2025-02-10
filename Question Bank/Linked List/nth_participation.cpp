/*Imagine a scenario of a lucky draw event and have a list of participants represented as a singly linked list.
Write a function that retrieves the N-th participant from the end of the linked list, where N is a 1-based
index. If N is greater than the number of participants or if the list is empty, the function should return
None. ( ‘N’ will be taken from user)*/
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

    void retrive(int n)
    {
        Node *temp; int cn=0,cn1=0;
        for(temp = start;temp!=nullptr;temp=temp->next)
        {
            cn++;
        }

        int size = cn - n;
        if(size<0) 
        {
            cout<<"None";
            return;
        }
        if (start == nullptr) {
            cout << "\nThe list is empty!" << endl;
            return;
        }
        for(temp=start;temp!=nullptr;temp=temp->next)
        {
            if(size == cn1)
            {
                cout<<temp->data<<'\t';
            }
            cn1++;
        }
        cout << endl;
    }
};



int main() {
    LinkedList l1;
    int p;

    cout<<"Enter the Nth participant: ";
    cin>>p;

    // Create the first linked list
    cout << "Create the first sorted linked list:\n";
    l1.create();

    l1.retrive(p);

    return 0;
}


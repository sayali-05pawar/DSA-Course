/*Write a function to partition a singly linked listaround a value x, such that all nodes less than x
come before nodes greater than or equal to x.*/
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to append a new node at the end of a linked list
void append(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to partition the linked list around value x
Node* partition(Node* head, int x) {
    Node* lessHead = nullptr;   // Head of the list for nodes < x
    Node* lessTail = nullptr;   // Tail of the list for nodes < x
    Node* greaterHead = nullptr; // Head of the list for nodes >= x
    Node* greaterTail = nullptr; // Tail of the list for nodes >= x

    while (head) {
        if (head->data < x) {
            // Add to the 'less' list
            if (!lessHead) {
                lessHead = lessTail = head;
            } else {
                lessTail->next = head;
                lessTail = head;
            }
        } else {
            // Add to the 'greater' list
            if (!greaterHead) {
                greaterHead = greaterTail = head;
            } else {
                greaterTail->next = head;
                greaterTail = head;
            }
        }
        head = head->next;
    }

    // Combine the two lists
    if (lessTail) {
        lessTail->next = greaterHead;
    }

    if (greaterTail) {
        greaterTail->next = nullptr; // End the greater list
    }

    return lessHead ? lessHead : greaterHead; // Return the new head
}

// Main function to test the implementation
int main() {
    Node* head = nullptr;

    // Create a linked list: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1
    append(head, 3);
    append(head, 5);
    append(head, 8);
    append(head, 5);
    append(head, 10);
    append(head, 2);
    append(head, 1);

    cout << "Original List: ";
    printList(head);

    // Partition the list around x = 5
    int x = 5;
    head = partition(head, x);

    cout << "Partitioned List around " << x << ": ";
    printList(head);

    return 0;
}
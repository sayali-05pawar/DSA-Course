/*Write a function to swap nodes in a doubly linked list without swapping data.*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    void swapNodes(int pos1, int pos2) {
        if (pos1 == pos2) {
            cout << "The two positions are the same. No swap needed." << endl;
            return;
        }

        // Find the nodes at the given positions
        Node* node1 = head;
        Node* node2 = head;
        int count1 = 1, count2 = 1;

        while (node1 != nullptr && count1 < pos1) {
            node1 = node1->next;
            count1++;
        }

        while (node2 != nullptr && count2 < pos2) {
            node2 = node2->next;
            count2++;
        }

        // If either node is not found, return
        if (node1 == nullptr || node2 == nullptr) {
            cout << "One or both positions are invalid." << endl;
            return;
        }

        // Swap node1 and node2 by updating pointers
        if (node1->prev != nullptr) {
            node1->prev->next = node2;
        } else {
            head = node2; // Update head if node1 was the head
        }

        if (node2->prev != nullptr) {
            node2->prev->next = node1;
        } else {
            head = node1; // Update head if node2 was the head
        }

        if (node1->next != nullptr) {
            node1->next->prev = node2;
        }

        if (node2->next != nullptr) {
            node2->next->prev = node1;
        }

        // Swap the prev and next pointers of node1 and node2
        Node* tempPrev = node1->prev;
        Node* tempNext = node1->next;

        node1->prev = node2->prev;
        node1->next = node2->next;

        node2->prev = tempPrev;
        node2->next = tempNext;
    }
};

int main() {
    DoublyLinkedList dll;
    int n, value;

    cout << "Enter the number of elements in the doubly linked list: ";
    cin >> n;

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        dll.append(value);
    }

    cout << "\nOriginal Doubly Linked List: ";
    dll.display();

    int pos1, pos2;
    cout << "\nEnter the positions of the nodes to swap (1-based index): ";
    cin >> pos1 >> pos2;

    dll.swapNodes(pos1, pos2);

    cout << "\nDoubly Linked List after swapping nodes: ";
    dll.display();

    return 0;
}

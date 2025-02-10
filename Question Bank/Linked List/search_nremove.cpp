#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
};

class LinkedList {
    Node *start;
	public:
	LinkedList()
	{
		start = NULL;	
	}
	
	void create()  
	{
		 Node *nnode;  
    	 Node *temp;    
   		 char ch;       
		do{
			nnode = new Node;   
			cout<<"Enter the number to be stored: ";  
			cin>>nnode -> data;   
			
			if(start == NULL) 
			{
				start = nnode;  
				nnode -> next = start;
			}	
			else 
			{
				 temp = start;
                while (temp->next != start) {
                    temp = temp->next;
                }
                temp->next = nnode;
                nnode->next = start;
			}
			cout<<"Do you have more data ?? \nIf yes than press 'y' else press 'n': ";
				cin>>ch;  
		}
		while (ch == 'y');  
	}
	
   void display()
	{
		Node *temp = start;
		cout<<"\nThe store numbers are: ";
		 do {
            cout << temp->data << '\t';
            temp = temp->next;
        } while (temp != start);
	}
	
     void removeDuplicates() {
        if (start == nullptr) return;

        Node* current = start;
        do {
            Node* runner = current;
            while (runner->next != start) {
                if (runner->next->data == current->data) {
                    // Remove duplicate node
                    Node* duplicate = runner->next;
                    runner->next = duplicate->next;

                    // If the duplicate is the start node, update start
                    if (duplicate == start) {
                        start = duplicate->next;
                    }

                    delete duplicate;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        } while (current->next != start);

        // If the last node itself is a duplicate, handle it separately
        if (current->data == start->data) {
            Node* runner = start;
            while (runner->next != current) {
                runner = runner->next;
            }
            runner->next = start; // Remove the duplicate
            delete current;
        }
    }
};

int main() {
    LinkedList l1;
    int search;

    l1.create();
    l1.display();
    cout << "\nEnter the duplicate number to be removed: ";
    cin >> search;

    l1.removeDuplicates();
    l1.display();
    
    return 0;
}

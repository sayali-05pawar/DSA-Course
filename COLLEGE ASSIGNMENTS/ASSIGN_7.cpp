/*Assignment No - 7
 Assignment Title - Implement a browser history management system using a stack data structure to track the user's browsing 
 history. The system should support the following functionalities: 
 a. Add visited page 
 b. Navigate back 
 c. View current page 
 d. Check if history is empty or not Assume no upper bound on number of pages visited.*/

#include <iostream>
using namespace std;

 class Node
 {
    private:
    string address;

    public:
    Node *next;

    Node()
    {
        next = nullptr;
    }

    void read()
    {
        cout<<"\nEnter the address: ";
        cin>>address;
        cout<<"\n--------------------------------\n";
    }

    string display()
    {
        return address;
    }
 };

 class browser
 {
    Node *top;
    public:

    browser()
    {
        top=nullptr;
    }

    bool isempty() {
        return top == nullptr;
    }

    void add_page()
    {
        Node *nnode = new Node;
        nnode->read();  
        if(isempty())
        {
            top=nnode;
        }
        else
        {
            nnode->next=top;
            top=nnode;
        }
        cout<<"\nVisited the page "<<top->display();
    }

    void navigate_back()
    {
         if (isempty()) {
            cout << "No pages in history!!\n";
        } else {
            Node *temp = top;
            top = top->next;
            delete temp;

            if (top != nullptr) {
                cout << "Navigated back to: " << top->display() << "\n";
            } else {
                cout << "Navigated back to the start of history\n";
            }
        }
    }

    void currentpage()
    {
        if(isempty())
        {
            cout<<"No pages in history!! ";
        }
        else
        {
            cout<<"\nCurrent page is "<<top->display();
        }
    }
 };

 int main()
 {
    browser b;
    int choice;

    while(1)
    {
        cout<<"\nMENU:- "
            <<"\n1.Add Visited Page"
            <<"\n2.Navigate Back"
            <<"\n3.View Current Page"
            <<"\n4.Check if history is empty or not"
            <<"\n5.Exit"
            <<"\nEnter your choice: ";
        cin>>choice;
        cout<<"\n--------------------------------\n";

        switch (choice)
        {
        case 1:
            b.add_page();
            break;
        case 2:
            b.navigate_back();
            break;
        case 3:
            b.currentpage();
            break;
        case 4:
        
            if (b.isempty()) {
                cout << "No pages in history!!\n";
            } else {
                cout << "History is not empty.\n";
            }
            break;
        case 5:
            cout<<"Exiting......";
            exit(0);

        default:
            cout<<"Invalid choice!!Please enter a valid choice.";
            break;
        
        
    }
    
 }
 return 0;
 }
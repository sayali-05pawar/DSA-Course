/* Assignment No - 5
 Assignment Title - Implement a navigation system for a delivery service using a circular linked list to represent routes. 
 The navigation system should support the following functionalities: 
 a. Add route 
 b. Remove route 
 c. Display route.*/

#include <iostream>
using namespace std;

class Node
{
    public:
    Node *next;
    string sou,des;
    float time,distance,charges;

    Node()
    {
        next=nullptr;
    }

    void read()
    {
        cout << "\nEnter the SOURCE Address: ";
        cin >> sou;
        cout << "\nEnter the DESTINATION Address: ";
        cin >> des;
        cout << "\nEnter the Distance Between source and destination in km: ";
        cin >> distance;
        cout << "\nTime required in minutes: ";
        cin >> time;
        cout << "\nCharges for Travelling: ";
        cin >> charges;
    }

    void display_nav()
    {
        cout << "\nSOURCE: " << sou;
        cout << "\nDESTINATION: " << des;
        cout << "\nDistance from " << sou << " to " << des << " is " << distance << " km.";
        cout << "\n" << time << " minutes are required to reach!!!";
        cout << "\nCharges: " << charges << " RS.";
        cout << "\n----------------------------------------------\n";
    }

};

class Navigation
{
    Node *start;
    public:

    Navigation()
    {
        start=nullptr;
    }

    void add()
    {
        Node*temp,*nnode;
        int n;

        cout<<"Enter how many routes to be added: ";
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            nnode = new Node;
            nnode->read();

            if(start==nullptr)
            {
                start=nnode;
                start->next=nnode;
            }
            else
            {
                for(temp=start;temp->next!=start;temp=temp->next);
                temp->next=nnode;
                nnode->next=start;
            }
        }
    }

    void remove()
    {
        Node *x,*temp=start;
        int pos,i;

        cout<<"Enter the position to remove route(starts from 0): ";
        cin>>pos;

        if(pos==0)
        {
            x=start;
            start=start->next;
            for(temp=start;temp!=start;temp=temp->next);
            temp->next=start;

            delete x;
        }
        else
        {
            for(int i=1;temp->next!=start && i<pos-1;i++)
            {
                temp=temp->next;
            }
            x=temp->next;
            temp->next=x->next;

            delete x;
        }
        display();
    }

    void display()
    {
        Node *temp = start; 
        cout << "\nThe stored Details are: ";
        do {
            temp->display_nav(); 
            temp = temp->next; // Move to the next route
        } while (temp != start); // Stop when we reach the first route again (circular list)
    }
};

int main()
{
    Navigation l;
    int choice;

    while (1)
    {
        cout << "\nMENU: "
             << "\n1.ADD ROUTE"
             << "\n2.REMOVE Route "
             <<"\n3.Display Route"
             << "\n4.Exit"
             << "\n------------------------------------------------";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            l.add();
            break;
        case 2:
            l.remove();
            break;
        case 3:
            l.display();
            break;
        case 4:
            cout << "\n\n-------------THANK YOU-------------\n\n";
            exit(0);
       
        default:
            cout << "\nInvalid choice! Please enter a valid choice !!!!! ";
            break;
        }
        cout << "\n----------------------------------------------";
    }
    return 0;
}


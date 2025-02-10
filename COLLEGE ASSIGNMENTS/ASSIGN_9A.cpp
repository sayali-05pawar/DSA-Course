/* Assignment No - 9(A)
 Assignment Title - Implement a restaurant waitlist system using the queue data structure. 
 Restaurant waitlist provide following facility: 
 a. Add Party to Waitlist 
 b. Seat Party 
 c. Display Waitlist*/

#include <iostream>
using namespace std;

class Queue
{
    int front,rear;
    string data[10];

    public:
    Queue()
    {
        front=0;
        rear=-1;
    }
    bool isempty()
    {
        return front==rear+1;;
    }
    bool isfull()
    {
        return rear==9;
    }

    void enqueue(string partyname)
    {
        if(isfull())
        {
            cout<<"Wailist is full.No paries allowed!!";
        }
        else{
            rear++;
            data[rear]=partyname;
            cout<<"Added "<<partyname<<" in waitlist.";
        }
    }

    string dequeue()
    {
        if(isempty())
        {
            cout<<"Wailist is empty.";
        }
        string partyn = data[front];
        front++;
        return partyn;
    }

    void display()
    {
        cout<<"The current waitlist:- ";
        for(int i = front;i<=rear;i++)
            cout<<data[i]<<'\t';
        cout<<endl;
    }
};

int main()
{
    Queue waitlist; 
    int choice; 
    string Name; 
    char ch; 
   
    while (1)
    {
       
        cout << "\nMENU: "
             << "\n1. Add Party to Waitlist"
             << "\n2. Seat Party"
             << "\n3. Display Waitlist"
             << "\n4. Exit"
             << "\n----------------------------";

        cout << "\nEnter your choice: ";
        cin >> choice; 

        switch (choice) 
        {
        case 1:
           
            cout << "Enter the Name to add to the waitlist: ";
            cin >> Name; 
            waitlist.enqueue(Name); 
            break;

        case 2:
        {
            
            string seatedParty = waitlist.dequeue(); 
            if (!seatedParty.empty()) 
                cout << seatedParty << " has been seated." << endl;
            break;
        }

        case 3:
            waitlist.display(); 
            break;

        case 4:
            cout << "\n-----------THANK YOU-----------\n";
            exit(0); 

        default:
            cout << "Enter a valid choice!" << endl; 
        }
    }

    return 0;
}
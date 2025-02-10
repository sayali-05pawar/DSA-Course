/* Assignment No - 4
 Assignment Title - Implement a simple text editor application using a doubly linked list to manage the text buffer.
 Text editor should support the following functionalities: 
 a. Insert text 
 b. Delete text 
 c. Display text 
 d. Search text 
 e. Print text in reverse.*/

 #include <iostream>
 using namespace std;

 class Node
 {
    public:
    string data;
    Node *next,*prev;

    Node()
    {
        next = nullptr;
        prev=nullptr;
    }

 };

 class text_editor
 {
    Node *start;
    public:
    text_editor()
    {
        start=nullptr;
    }
    
    void create()
    {
        Node *temp;
        int n;

        cout<<"Enter how many text you want to add: ";
        cin>>n; 
        for(int i =0;i<n;i++)
        {
            Node *nnode=new Node;
            cout<<"Enter the text: ";
            cin>>nnode->data;

            if(start==nullptr)
            {
                start=nnode;
            }
            else
            {
                for(temp=start;temp->next!=nullptr;temp=temp->next);
                temp->next = nnode;
                nnode->prev=temp;
            }
        }
    
    }

    void insert()
    {
        Node *temp=start,*nnode;
        int pos,i=1;

        nnode = new Node;
        cout<<"Enter the new text to be inserted: ";
        cin>>nnode->data;

        cout<<"Enter the position to insert text(starts from 0): ";
        cin>>pos;

        if(pos==0)
        {
            nnode->next=start;
            start->prev=nnode;
            start=nnode;

        }
        else
        {
            for(i = 1;temp->next!=nullptr && i<pos;i++)
            {
                temp=temp->next;
            }
                nnode->next=temp->next;
                temp->next=nnode;
                nnode->prev=temp;
                if(nnode->next!=nullptr)
                    nnode->next->prev=nnode;
        }
        display();
    }

    void del()
    {
     Node *temp=start,*x;
        int pos,i=1;
        
        cout<<"Enter the position to delete text(starts from 0): ";
        cin>>pos;

        if(pos==0)
        {
            x=start;
            start  = start->next;
            if(start!=nullptr)
                start->prev=nullptr;
            delete x;

        }
        else
        {
            for(i = 0;temp!=nullptr && i<pos;i++)
            {
                temp=temp->next;
            }
                x=temp;
                temp->prev->next=temp->next;
                if(temp->next!=nullptr)
                    temp->next->prev = temp->prev;
                delete x;
        }
        display();   
    }

    void issearch()
    {
        int found = 0;
        string n;
        Node *temp;
        cout << "\nEnter the text to be searched: ";
        cin >> n;

        // Traverse to search for the text
        for (temp = start; temp != NULL; temp = temp->next)
        {
            if (temp->data == n)  // Match found
            {   
                found = 1;  // Mark as found
                break;
            }
        }

        if (found == 1)
            cout << "Text is found!!";
        else
            cout << "Text is not found!";
    }

    void display()
    {
        Node *temp;
        cout << "\nThe stored text is: ";
        for (temp = start; temp != NULL; temp = temp->next)
        {
            cout << temp->data << '\t';  // Print the text in each node
        }
    }

    // Function to display the text in reverse order
    void dis_rev()
    {
        Node *temp;
        cout<<"Reversing text: ";
        for(temp=start;temp->next!=nullptr;temp=temp->next);
        for(;temp!=nullptr;temp=temp->prev)
            cout<<temp->data<<'\t';
    }
 };

 int main()
{
    text_editor p;
    int n,choice;

    while(1)
    {
        cout<<"\nMENU:- "
            <<"\n1.Create text list"
            <<"\n2.Insert text"
            <<"\n3.Delete text"
            <<"\n4.Display text"
            <<"\n5.Search text"
            <<"\n6.Print text in reverse order"
            <<"\n7.Exit"
            <<"\nEnter your choice: ";
        cin>>choice;
        cout<<"\n-----------------------------------\n";

        switch (choice)
        {
        case 1:
            p.create();
            break;
        
        case 2:
            p.insert();
            break;

        case 3:
            p.del();
            break;
        
        case 4:
            p.display();
            break;

        case 5:
            p.issearch();
            break;

        case 6:
            p.dis_rev();
            break;

        case 7:
            cout<<"\nThank You >_< !!!";
            exit(0);

        default:
            cout<<"\nInvalid Choice! Please Enter a valid choice.";

        }
    }
    return 0;

}
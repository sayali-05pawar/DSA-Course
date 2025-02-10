/*Assignment No - 3
 Assignment Title - Consider the playlist in a music player. Implement a playlist feature in music player application 
 using singly linked list. Each song in the playlist is represented as a node in the linked list. Each node contains 
 information about the song (such as title or artist or duration, etc.). The playlist should allow users to: 
 a. Add songs 
 b. Remove songs 
 c. Display the entire playlist 
 d. Play specific songs.*/

#include <iostream>
using namespace std;

class Song
{ 
    private:
    string title,artist;
    int duration;

    public:
    Song *next;
    Song()
    {
        next = nullptr;
    }

    void add_songs()
    {
        cout<<"\nEnter the Song Details:- ";
        cout<<"\nTitle of the song: ";
        cin>>title;
        cout<<"\nArtist Name: ";
        cin>>artist;
        cout<<"\nDuration of the Song(in min): ";
        cin>>duration;
        cout<<"\n-------------------------------\n";
    }

    void display_songs()
    {
        cout<<"\nTitle of the song: "<<title;
        cout<<"\nArtist Name: "<<artist;
        cout<<"\nDuration of the Song(in min): "<<duration;
        cout<<"\n-------------------------------\n";
    }

    string get_title()
    {
        return title;
    }
};

class Playlist
{
    public:
    Song *start;

    Playlist()
    {
        start=nullptr;
    }

    void create()
    {
        int n;
        Song *temp;
        cout<<"Enter how many song you want to add: ";
        cin>>n;
        for(int i =0 ;i<n;i++)
        {
            Song *nnode = new Song;
            nnode->add_songs();


            if(start == nullptr)
            {
                start = nnode;
            }
            else
            {
                temp=start;
                while (temp->next!=nullptr)
                {
                    temp=temp->next;
                }
                temp->next=nnode;  
            }
        }
    }

    void insert()
    {
        Song *temp,*nnode;
        int pos,i=1;

        nnode = new Song;
        cout<<"---------------NEW SONG---------------- ";
        nnode->add_songs();

        cout<<"Enter the position to insert song(0 for start): ";
        cin>>pos;

        if(pos==0)
        {
            nnode->next = start;
            start = nnode;
        }
        else
        {
            Song *temp = start;
            for (int i = 1; temp != nullptr && i < pos; i++)
            {
                temp = temp->next;
            }

            if (temp == nullptr)
            {
                cout << "Position out of bounds. Adding at the end.\n";
                temp = start;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = nnode;
            }
            else
            {
                nnode->next = temp->next;
                temp->next = nnode;
            }
        }
        display_playlist();
    }

    void remove()
    {
        Song *temp,*x;
        int pos,i=1;

        cout<<"Enter the position to delete the song(start from 0): ";
        cin>>pos;

        if(pos==0)
        {
            x=start;
            start=start->next;

            delete x;
        }
        else
        {
            Song *temp = start;
            for (int i = 1; temp->next != nullptr && i < pos; i++)
            {
                temp = temp->next;
            }

            if (temp->next == nullptr)
            {
                cout << "Position out of bounds.\n";
            }
            else
            {
                x = temp->next;
                temp->next = x->next;
                delete x;
            }
        }
        display_playlist();
    }

    void display_playlist()
    {
        Song *temp;
        if (start == nullptr)
        {
            cout << "The playlist is empty.\n";
            return;
        }

        temp=start;
       while (temp!=nullptr)
       {
            temp->display_songs();
            temp=temp->next;
       }
       
    }

    void issearch()
    {
        Song *temp;
        string search;
        int found = 0;

        cout << "Enter the title of the song you want to play: ";
        cin >> search;

        for (temp = start; temp != nullptr; temp = temp->next) {
            if (temp->get_title() == search) {
                cout << "Song Found and Played >_<....\n";
                temp->display_songs();
                found = 1;
                break;
            }
        }

        if (!found) {
            cout << "Song not found!!!\n";
        }
    }
};

int main()
{
    Playlist p;
    int n,choice;

    while(1)
    {
        cout<<"\nMENU:- "
            <<"\n1.Add Songs"
            <<"\n2.Insert New Songs"
            <<"\n3.Remove Songs"
            <<"\n4.Display the entire Playlist"
            <<"\n5.Play Specific Songs"
            <<"\n6.Exit"
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
            p.remove();
            break;
        
        case 4:
            p.display_playlist();
            break;

        case 5:
            p.issearch();
            break;

        case 6:
            cout<<"\nThank You >_< !!!";
            exit(0);

        default:
            cout<<"\nInvalid Choice! Please Enter a valid choice.";

        }
    }
    return 0;

}
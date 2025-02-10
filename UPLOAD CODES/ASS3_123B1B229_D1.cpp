/* Name - SAYALI PAWAR
 Roll no - SYCOD229
 PRN - 123B1B229
 Div - D

 Assignment No - 3
 Assignment Title - Consider the playlist in a music player. Implement a playlist feature in music player application 
 using singly linked list. Each song in the playlist is represented as a node in the linked list. Each node contains 
 information about the song (such as title or artist or duration, etc.). The playlist should allow users to: 
 a. Add songs 
 b. Remove songs 
 c. Display the entire playlist 
 d. Play specific songs.*/

#include <iostream>
using namespace std;

// Class representing a Song
class Song
{
    string title;
    string singer;

public:
    Song *next; // Pointer to the next Song in the playlist
    Song()
    {
        next = nullptr; // Initialize the next pointer to nullptr
    }
    
    // Function to read the song's details (title and singer)
    void read();

    // Function to display the song's details (used to display the playlist)
    void display_playlist();

    // Getter function to get the title of the song
    string get_title();

    // Getter function to get the singer of the song
    string get_singer();

    // Setter function to set the title and singer of the song
    void setsinger(string t, string s);
};

// Function to read the song's details
void Song::read()
{
    cout << "\nEnter the TITLE: ";
    cin >> title;
    cout << "\nEnter the SINGER: ";
    cin >> singer;
}

// Function to display the song's details
void Song::display_playlist()
{
    cout << "\nTITLE: " << title;
    cout << "\nSINGER: " << singer;
}

// Getter function to return the title of the song
string Song::get_title()
{
    return title;
}

// Getter function to return the singer of the song
string Song::get_singer()
{
    return singer;
}

// Setter function to modify the title and singer of the song
void Song::setsinger(string t, string s)
{
    title = t;
    singer = s;
}

//-----------------------------------------------------------------------------------------------------------------

// Class representing a Playlist (linked list of songs)
class Playlist
{
    Song *start; // Pointer to the first song in the playlist

public:
    Playlist()
    {
        start = nullptr; // Initialize the playlist to empty (nullptr)
    }

    // Function to create a playlist (add songs)
    void create();

    // Function to display all songs in the playlist
    void display_playlist();

    // Function to insert a song at the beginning of the playlist
    void ins_beg();

    // Function to insert a song at a specific position in the playlist
    void ins_between();

    // Function to insert a song at the end of the playlist
    void ins_end();

    // Function to delete the song at the beginning of the playlist
    void del_beg();

    // Function to delete a song at a specific position in the playlist
    void del_between();

    // Function to delete the song at the end of the playlist
    void del_end();

    // Function to search for a specific song in the playlist
    void issearch();

    // Function to modify the details of a song
    void modify();
};

// Function to create the playlist (allows the user to add songs)
void Playlist::create()
{
    Song *nSong;  // Pointer to the new song
    Song *temp;   // Temporary pointer to traverse the playlist
    char ch;      // Variable to check if user wants to add more songs

    do
    {
        nSong = new Song;   // Allocate memory for a new song
        nSong->read();      // Read song details
        if (start == nullptr) // If playlist is empty, add the song as the first song
        {
            start = nSong;
        }
        else // If playlist already has songs, insert the new song at the end
        {
            temp = start;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = nSong;
        }
        cout << "Do you have more Songs to be added(y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

// Function to display all songs in the playlist
void Playlist::display_playlist()
{
    Song *temp;
    cout << "\nThe stored Songs are: ";
    for (temp = start; temp != nullptr; temp = temp->next)
    {
        cout << "\nTITLE: " << temp->get_title() << '\t';
        cout << "\nSINGER: " << temp->get_singer() << '\t';
        cout << "\n";
    }
}

// Function to insert a song at the beginning of the playlist
void Playlist::ins_beg()
{
    Song *nSong; // New song to be inserted
    nSong = new Song;
    cout << "Enter a Song to be inserted at the beginning: ";
    nSong->read();
    
    nSong->next = start; // Make the new song point to the current first song
    start = nSong;       // Update start to the new song

    display_playlist();
}

// Function to insert a song after a specific song
void Playlist::ins_between()
{
    Song *nSong, *temp;
    string n; // Title of the song after which the new song will be inserted

    nSong = new Song;
    cout << "\nEnter a Song to be inserted: ";
    nSong->read();

    cout << "Enter the Title after which you want to insert: ";
    cin >> n;
    for (temp = start; temp != nullptr; temp = temp->next)
    {
        if (temp->get_title() == n)
        {
            nSong->next = temp->next; // Insert the new song between temp and temp->next
            temp->next = nSong;
            break;
        }
    }

    display_playlist();
}

// Function to insert a song at the end of the playlist
void Playlist::ins_end()
{
    Song *nSong, *temp;

    nSong = new Song;
    cout << "\nEnter a Song to be inserted at the end: ";
    nSong->read();

    for (temp = start; temp->next != nullptr; temp = temp->next)
    {
    }
    temp->next = nSong; // Insert at the end

    display_playlist();
}

// Function to delete the first song in the playlist
void Playlist::del_beg()
{
    Song *x; // Pointer to the song to be deleted

    x = start;
    start = start->next; // Move start to the next song
    delete x;            // Delete the first song

    display_playlist();
}

// Function to delete a song by its title
void Playlist::del_between()
{
    Song *x, *temp;
    string n; // Title of the song to be deleted

    cout << "Enter the Song's Title which you want to delete: ";
    cin >> n;
    for (temp = start; temp != nullptr; temp = temp->next)
    {
        if (temp->next->get_title() == n)
        {
            x = temp->next;      // x points to the song to be deleted
            temp->next = x->next; // Remove the song from the playlist
            delete x;             // Delete the song
            break;
        }
    }

    display_playlist();
}

// Function to delete the last song in the playlist
void Playlist::del_end()
{
    Song *x, *temp;

    for (temp = start; temp->next->next != nullptr; temp = temp->next)
    {
    }
    x = temp->next; // x points to the last song
    temp->next = nullptr;
    delete x;

    display_playlist();
}

// Function to search for a specific song and play it
void Playlist::issearch()
{
    int found = 0;
    string n; // Title of the song to be searched
    Song *temp;
    cout << "\nEnter the Song's Title to be played: ";
    cin >> n;
    for (temp = start; temp != nullptr; temp = temp->next)
    {
        if (temp->get_title() == n)
        {
            cout << "\nTITLE: " << temp->get_title() << '\t';
            cout << "\nSINGER: " << temp->get_singer() << '\t';
            cout << "\n";
            found = 1;
            break;
        }
    }
    if (found == 1)
        cout << "Song found & Played!!";
    else
        cout << "Song not found";
}

// Function to modify the details of a song
void Playlist::modify()
{
    int found = 0;
    string ntitle, nsinger, n;
    cout << "\nEnter the Song's title which you want to Modify: ";
    cin >> n;
    cout << "Enter the new TITLE: ";
    cin >> ntitle;
    cout << "Enter the new SINGER: ";
    cin >> nsinger;
    Song *temp;
    for (temp = start; temp != nullptr; temp = temp->next)
    {
        if (temp->get_title() == n)
        {
            temp->setsinger(ntitle, nsinger); // Modify the song's details
            found = 1;
            break;
        }
    }
    if (found == 1)
        cout << "The Song is MODIFIED!!!";
    else
        cout << "Song not MODIFIED";
}

// Main function with a menu-driven interface to manage the playlist
int main()
{
	Playlist l;
	int choice;
	char ch;
	while(true)
    {
    	cout<<"\nMENU: "
    		<<"\n1.Add Songs"
    		<<"\n2.Display Songs"
			<<"\n3.Play Particular Song"
    		<<"\n4.Insert Song at beginning"
    		<<"\n5.Insert Song in between any position "
    		<<"\n6.Insert Song at end"
    		<<"\n7.Delete Song of beginning"
    		<<"\n8.Delete Song of an position in between"
    		<<"\n9.Delete Song of end"
			<<"\n10.Modify Song"
            <<"\n11.Exit"
    		<<"\n------------------------------------------------";
    		
    	cout<<"\nEnter the menu: ";
		cin>>choice;	

    	switch (choice) {
        	case 1: 
            	l.create();
            	break;

        	case 2: 
            	l.display_playlist();
            	break;

			case 3:
				l.issearch();
				break;

        	case 4: 
	        	l.ins_beg();
            	break;
      	
        	case 5: 
            	l.ins_between();
            	break;
        	
        	case 6: 
	         	l.ins_end();
            	break;
        	
        	case 7: 
            	l.del_beg();
            	break;
        	
        	case 8: 
            	l.del_between();
            	break;
        	
        	case 9: 
            	l.del_end();
            	break;
        	
			case 10:
				l.modify();
				break;

            case 11:
				cout<<"\nThank you!!!\n";
                exit(0);
            
        	default:
            	cout << "\nInvalid choice! Please enter a valid choice !!!!! ";
            	break;
    		}
    	cout<<"\n----------------------------------------------";
    	
	}

	return 0;	
}

/*You have a music playlist represented as a singly linked list. Each node in the linked list represents a
song (title, artist, duration). Write a recursive function to find out whether a particular song is present in the playlist.*/
#include <iostream>
using namespace std;

class Song {
public:
    string title;
    string singer;

    Song* next;

    Song() {
        next = nullptr;
    }

    void read();
    void display();
    string get_title();
};

void Song::read() {
    cout << "Enter the TITLE: ";
    cin >> title;
    cout << "Enter the SINGER: ";
    cin >> singer;
}

void Song::display() {
    cout << "\nTITLE: " << title;
    cout << "\nSINGER: " << singer;
}

string Song::get_title() {
    return title;
}

class Playlist {
    Song* head;

public:
    Playlist() {
        head = nullptr;
    }

    void addsong() {
        char choice;
        do {
            Song* nnode = new Song;
            nnode->read();
            if (head == nullptr) {
                head = nnode;
            } else {
                Song* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = nnode;
            }
            cout << "\nDo you want to add more songs???(y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }

    void del_song() {
        string title_del;
        cout << "Enter the title that has to be deleted: ";
        cin >> title_del;

        Song* prev = nullptr;
        Song* cn = head;
        while (cn != nullptr) {
            if (cn->title == title_del) {
                if (prev == nullptr) {
                    // Deleting the head node
                    head = cn->next;
                } else {
                    prev->next = cn->next;
                }
                delete cn;
                cout << "\nThe given title is deleted successfully!!";
                return;
            }
            prev = cn;
            cn = cn->next;
        }
        cout << "\nTitle not found......";
    }

    void display_playlist() {
        Song* cn = head;
        while (cn != nullptr) {
            cn->display();
            cn = cn->next;
        }
    }

    bool find_song_recursive(Song* node, string& title) {
        if (node == nullptr) {
            return false; // Base case: reached end of list
        }
        if (node->title == title) {
            return true; // Found the song
        }
        return find_song_recursive(node->next, title); // Recursive step
    }

    bool find_song(string& title) {
        return find_song_recursive(head, title);
    }
};

int main() {
    Playlist p1;
    p1.addsong();

    string search_title;
    cout << "\nEnter the title of the song to search: ";
    cin >> search_title;

    if (p1.find_song(search_title)) {
        cout << "\nSong \"" << search_title << "\" is present in the playlist!";
    } else {
        cout << "\nSong \"" << search_title << "\" is NOT present in the playlist.";
    }

    cout << "\nThe songs details are:- ";
    p1.display_playlist();

    return 0;
}

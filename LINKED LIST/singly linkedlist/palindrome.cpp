/*Fuction to check if the singly linkedlist is palindrome*/
#include <iostream>
using namespace std;

class Node
{
public:
    int no;
    Node *next;
    Node()
    {
        no = 0;
        next = NULL;
    }
};

class linkedlist
{
    Node *start;

public:
    linkedlist()
    {
        start = NULL;
    }

    void create()
    {
        Node *nnode;
        Node *temp;
        char ch;
        do
        {
            nnode = new Node;
            cout << "Enter the number to be stored: ";
            cin >> nnode->no;

            if (start == NULL)
            {
                start = nnode;
            }
            else
            {
                temp = start;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = nnode;
            }
            cout << "Do you have more data (y/n)?? :";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
    }

    Node* reverse(Node* head)
    {
        Node *prev = NULL, *current = head, *next = NULL;
        while (current != NULL)
        {
            next = current->next; // Store next
            current->next = prev; // Reverse current node's pointer
            prev = current;       // Move pointers one position ahead.
            current = next;
        }
        return prev;
    }

    bool isPalindrome()
    {
        if (start == NULL || start->next == NULL)
            return true;

        // Step 1: Find the middle of the linked list
        Node *slow = start, *fast = start;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        Node *secondHalfStart = reverse(slow);

        // Step 3: Compare the first half with the reversed second half
        Node *firstHalfStart = start;
        Node *secondHalfIter = secondHalfStart;
        while (secondHalfIter != NULL)
        {
            if (firstHalfStart->no != secondHalfIter->no)
            {
                return false;
            }
            firstHalfStart = firstHalfStart->next;
            secondHalfIter = secondHalfIter->next;
        }

        // Optional: Restore the list by reversing the second half again (to maintain the original list structure)
        reverse(secondHalfStart);

        return true;
    }

    void display()
    {
        Node *temp;
        cout << "\nThe stored numbers are: ";
        for (temp = start; temp != NULL; temp = temp->next)
        {
            cout << temp->no << '\t';
        }
        cout << endl;
    }
};

int main()
{
    linkedlist l;
    l.create();

    l.display(); // Display the list

    if (l.isPalindrome())
    {
        cout << "\nThe list is a palindrome." << endl;
    }
    else
    {
        cout << "\nThe list is not a palindrome." << endl;
    }
    

    return 0;
}



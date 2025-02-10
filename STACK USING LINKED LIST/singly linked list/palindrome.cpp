/*Fuction to check if the singly linkedlist is palindrome*/
#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};

class Stack
{
    Node *top;

    public:
    Stack()
    {
        top = NULL;
    }

    void push(int no)
    {
        Node *nnode = new Node;
        if (nnode == NULL)
        {
            cout << "\nSTACK IS OVERFLOW ";
        }
        else
        {
            nnode->data = no;
            if (top == NULL)
            {
                top = nnode;
            }
            else
            {
                nnode->next = top;
                top = nnode;
            }
        }
    }

    int pop()
    {
        if (top == NULL)
        {
            cout << "\nSTACK IS UNDERFLOW ";
            return -1; // Return an error value
        }

        int n = top->data;
        Node *x = top;
        top = top->next;

        delete x;
        return n;
    }

    int isempty()
    {
        return top == NULL;
    }

    // Function to copy the stack into an array
    void copyStack(int arr[], int& idx)
    {
        Node* temp = top;
        while (temp != NULL)
        {
            arr[idx++] = temp->data;
            temp = temp->next;
        }
    }

    void display()
    {
        Node *temp;
        for (temp = top; temp != NULL; temp = temp->next)
            cout << temp->data << '\t';
        cout << endl;
    }

    // Function to check if the stack forms a palindrome
    bool isPalindrome()
    {
        // First, copy the stack elements into an array
        int size = 0;
        Node* temp = top;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }

        int* arr = new int[size];
        int idx = 0;
        copyStack(arr, idx);

        // Check if the array is a palindrome
        for (int i = 0; i < size / 2; i++)
        {
            if (arr[i] != arr[size - i - 1])
            {
                delete[] arr;
                return false;
            }
        }

        delete[] arr;
        return true;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(2);
    s.push(1);

    s.display(); // Display the stack

    if (s.isPalindrome())
    {
        cout << "The stack is a palindrome." << endl;
    }
    else
    {
        cout << "The stack is not a palindrome." << endl;
    }

    return 0;
}

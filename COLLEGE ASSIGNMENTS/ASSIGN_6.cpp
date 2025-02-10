/* Assignment No - 6
 Assignment Title - Consider two polynomial expressions of any degree. Design solution to perform addition of these two
 polynomials with suitable data structure and display results.*/

#include <iostream>
using namespace std;

class Node
{
    public:
    int coeff,exp;
    Node *next;

    Node()
    {
        coeff = 0;
        exp = 0;
        next = nullptr;
    }
    Node(int c,int e)
    {
        coeff = c;
        exp = e;
        next = nullptr;;
    }
};

class Polynomial
{
    Node *head;

    public:
    Polynomial()
    {
        head=nullptr;
    }

    void insertNode(int c,int e)
    {
        Node *nnode = new Node(c,e);
        if(head==nullptr || head->exp < nnode->exp)
        {
            nnode->next = head;
            head = nnode;
        }
        else
        {
            Node *temp;
            while(temp->next && temp->next->exp >= nnode->exp)
            {
                temp = temp->next;
            }
            if(temp->exp == nnode->exp)
            {
                temp->coeff = temp->coeff + nnode->coeff;
            }
            else
            {
                nnode->next = temp->next;
                temp->next = nnode;
            }
        }
    }

    Polynomial addition(Polynomial &p)
    {
        Node *h1 = head;
        Node *h2 = p.head;
        Polynomial result;

        if(h1==nullptr)
        {
            result.head = h2;
            return result;
        }
        if(h2==nullptr)
        {
            result.head = h1;
            return result;
        }

        while(h1!=nullptr && h2!=nullptr)
        {
            if(h1->exp == h2->exp)
            {
                result.insertNode(h1->coeff+h2->coeff,h1->exp);
                h1 = h1->next;
                h2 = h2->next;
            }
            else if(h1->exp > h2->exp)
            {
                result.insertNode(h1->coeff,h1->exp);
                h1 = h1->next;
            }
            else
            {
                result.insertNode(h2->coeff,h2->exp);
                h2 = h2->next;
            }
        }

        while(h1!=nullptr)
        {
            result.insertNode(h1->coeff,h1->exp);
            h1 = h1->next;
        }

        while(h2!=nullptr)
        {
            result.insertNode(h2->coeff,h2->exp);
            h2 = h2->next;
        }
        return result;
    }

    Polynomial subtraction(Polynomial &p)
    {
        Node *h1 = head;
        Node *h2 = p.head;
        Polynomial result;

        if(h1==nullptr)
        {
            result.head = h2;
            return result;
        }
        if(h2==nullptr)
        {
            result.head = h1;
            return result;
        }

        while(h1!=nullptr && h2!=nullptr)
        {
            if(h1->exp == h2->exp)
            {
                result.insertNode(h1->coeff-h2->coeff,h1->exp);
                h1 = h1->next;
                h2 = h2->next;
            }
            else if(h1->exp > h2->exp)
            {
                result.insertNode(h1->coeff,h1->exp);
                h1 = h1->next;
            }
            else
            {
                result.insertNode(-h2->coeff,h2->exp);
                h2 = h2->next;
            }
        }

        while(h1!=nullptr)
        {
            result.insertNode(h1->coeff,h1->exp);
            h1 = h1->next;
        }

        while(h2!=nullptr)
        {
            result.insertNode(h2->coeff,h2->exp);
            h2 = h2->next;
        }
        return result;
    }

    Polynomial mul(Polynomial &p)
    {
        Node *h1,*h2;
        Polynomial result;
        for(h1 = head; h1!=nullptr; h1=h1->next)
        {
            for(h2 = p.head; h2!=nullptr; h2=h2->next)
            {
                result.insertNode(h1->coeff*h2->coeff,h1->exp+h2->exp);
            }
        }
        return result;
    }

    void display()
    {
        Node *temp = head;
        // Traverse the linked list and print each term
        while (temp != NULL)
        {
            cout << temp->coeff << "x^" << temp->exp;
            if (temp->next != NULL)
                cout << " + "; // Print '+' if more terms are remaining
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Polynomial poly1, poly2, result; // Two polynomials and the result polynomial
    int choice, coeff, exp;

    while (1)
    {
        // Display the menu options
        cout << "\n*** Polynomial Operations Menu ***\n";
        cout << "1. Insert term in Polynomial 1\n";
        cout << "2. Insert term in Polynomial 2\n";
        cout << "3. Add Polynomials\n";
        cout << "4. Subtract Polynomials\n";
        cout << "5. Multiply Polynomials\n";
        cout << "6. Display Polynomial 1\n";
        cout << "7. Display Polynomial 2\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform actions based on user choice
        switch (choice)
        {
        case 1:
            // Insert term in Polynomial 1
            cout << "Enter coefficient and exponent for Polynomial 1: ";
            cin >> coeff >> exp;
            poly1.insertNode(coeff, exp);
            break;

        case 2:
            // Insert term in Polynomial 2
            cout << "Enter coefficient and exponent for Polynomial 2: ";
            cin >> coeff >> exp;
            poly2.insertNode(coeff, exp);
            break;

        case 3:
            // Add the two polynomials
            result = poly1.addition(poly2);
            cout << "Resultant Polynomial after Addition: ";
            result.display();
            break;

        case 4:
            // Subtract the two polynomials
            result = poly1.subtraction(poly2);
            cout << "Resultant Polynomial after Subtraction: ";
            result.display();
            break;

        case 5:
            // Multiply the two polynomials
            result = poly1.mul(poly2);
            cout << "Resultant Polynomial after Multiplication: ";
            result.display();
            break;

        case 6:
            // Display Polynomial 1
            cout << "Polynomial 1: ";
            poly1.display();
            break;

        case 7:
            // Display Polynomial 2
            cout << "Polynomial 2: ";
            poly2.display();
            break;

        case 8:
            // Exit the program
            cout << "Exiting program...\n";
            exit(0);

        default:
            // Handle invalid choices
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
/* Name - SAYALI PAWAR
 Roll no - SYCOD229
 PRN - 123B1B229
 Div - D

 Assignment No - 6
 Assignment Title - Consider two polynomial expressions of any degree. Design solution to perform addition of these two
 polynomials with suitable data structure and display results.*/

#include <iostream>
using namespace std;

// Node class representing each term in a polynomial
class Node
{
public:
    int coeff, expo; // Coefficient and exponent of the polynomial term
    Node *next;      // Pointer to the next term in the polynomial

    // Constructor to initialize the node
    Node()
    {
        coeff = 0;
        expo = 0;
        next = NULL; // Initialize next as NULL
    }
};

// Polynomial class representing the polynomial expression
class Polynomial
{
    Node *start; // Pointer to the first term of the polynomial

public:
    // Constructor to initialize the polynomial
    Polynomial()
    {
        start = NULL; // Initialize start as NULL
    }

    // Function to create a polynomial by adding terms
    void create()
    {
        Node *nnode; // Pointer to create new node
        Node *temp;  // Temporary pointer to traverse the polynomial
        int n;       // Number of terms to be added
        cout << "Enter the terms: ";
        cin >> n; // Input the number of terms

        do
        {
            nnode = new Node; // Create a new node
            cout << "Enter the co-efficient: ";
            cin >> nnode->coeff; 
            cout << "Enter the power of exponent: ";
            cin >> nnode->expo; 

            // If the polynomial is empty, set start to the new node
            if (start == NULL)
            {
                start = nnode;
            }
            else
            {
                // Otherwise, traverse to the end and add the new node
                temp = start;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = nnode;
            }
            n--; // Decrement the number of terms
        } while (n > 0); // Continue until all terms are entered
    }

    // Function to insert a new node in the polynomial
    void insert(Node *nnode)
    {
        Node *temp;

        // If the polynomial is empty, set start to the new node
        if (start == NULL)
        {
            start = nnode;
        }
        else
        {
            // Otherwise, traverse to the end and add the new node
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = nnode;
        }
    }

    // Function to display the polynomial
    void display()
    {
        Node *temp;
        cout << "\nThe polynomial expression is: ";
        for (temp = start; temp != NULL; temp = temp->next)
        {
            // Display each term of the polynomial
            cout << temp->coeff << "x ^" << temp->expo << "+";
        }
        cout << "\b\b"; // Remove the last "+" sign
    }

    // Function to add two polynomials
    void add(Polynomial p1, Polynomial p2)
    {
        Node *t1, *t2, *temp, *nnode;

        t1 = p1.start; // Pointer to traverse the first polynomial
        t2 = p2.start; // Pointer to traverse the second polynomial

        // Traverse both polynomials and add terms
        while (t1 != NULL && t2 != NULL)
        {
            nnode = new Node; // Create a new node for the result

            // If the exponent of the first polynomial is greater
            if (t1->expo > t2->expo)
            {
                nnode->expo = t1->expo; 
                nnode->coeff = t1->coeff; 
                t1 = t1->next; // Move to the next term in p1
            }
            // If the exponent of the second polynomial is greater
            else if (t2->expo > t1->expo)
            {
                nnode->expo = t2->expo; 
                nnode->coeff = t2->coeff; 
                t2 = t2->next; // Move to the next term in p2
            }
            // If exponents are equal, add coefficients
            else if (t1->expo == t2->expo)
            {
                nnode->expo = t1->expo; 
                nnode->coeff = t1->coeff + t2->coeff; 
                t1 = t1->next; // Move to the next term in p1
                t2 = t2->next; // Move to the next term in p2
            }
            insert(nnode); // Insert the new node into the result polynomial
        }

        // Add remaining terms from the first polynomial
        while (t1 != NULL)
        {
            nnode = new Node; // Create a new node for the result
            nnode->expo = t1->expo; 
            nnode->coeff = t1->coeff; 
            t1 = t1->next; // Move to the next term
            insert(nnode); // Insert the new node into the result polynomial
        }

        // Add remaining terms from the second polynomial
        while (t2 != NULL)
        {
            nnode = new Node; // Create a new node for the result
            nnode->expo = t2->expo; 
            nnode->coeff = t2->coeff; 
            t2 = t2->next; // Move to the next term
            insert(nnode); // Insert the new node into the result polynomial
        }

        cout << "\nAddition :"; // Indicate that addition is complete
    }
};

int main()
{
    Polynomial p1, p2, p3; // Create three polynomial objects
    p1.create(); // Create the first polynomial
    p2.create(); // Create the second polynomial

    p3.add(p1, p2); // Add the two polynomials
    p3.display(); // Display the result
    return 0;
}

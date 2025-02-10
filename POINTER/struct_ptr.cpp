#include <iostream>
using namepsace std;

// Define the Rectangle structure
struct Rectangle 
{
    int length=5;
    int breadth=10;
};

int main() 
{
    // Creating a pointer to structure variable
    Rectangle r1;
    r1.length;
    r1.breadth;

    Rectangle *ptr_Rect = &r1;

    cout << "Using pointer:" << endl;
    cout << "Length: " << ptr_Rect->length << endl;
    cout << "Breadth: " << ptr_Rect->breadth << endl;

    // Using dynamic memory allocation
    Rectangle *ptr_dy = new Rectangle;
    ptr_dy->length = 7;
    ptr_dy->breadth = 12;

   
    cout << "\nUsing dynamic memory allocation:" << endl;
    cout << "Length: " << ptr_dy->length << endl;
    cout << "Breadth: " << ptr_dy->breadth << endl;

    return 0;
}



#include <algorithm> /*#include <algorithm> includes the algorithm library, 
                        which provides various algorithms, including std::reverse.*/ 
#include <iostream>

int main()
{
    int originalArray[] = { 1, 2, 3, 4, 5 };
    int length = sizeof(originalArray) / sizeof(originalArray[0]);

    // Using inbuilt method in C++
    std::reverse(originalArray, originalArray + length);
    /*std::reverse is called with two arguments: a pointer to the beginning of the array (originalArray) and 
    a pointer to one past the end of the array (originalArray + length).
    This reverses the order of the elements in originalArray.*/

    
    // Print the reversed array
    for (int i = 0; i < length; i++) {
        std::cout << originalArray[i] << " ";
    }

    return 0;
}
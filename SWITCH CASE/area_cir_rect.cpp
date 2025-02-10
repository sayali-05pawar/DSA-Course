#include <iostream>
using namespace std;

int main() {
    int choice;
    cout << "Enter 1 to calculate the area of a circle\n";
    cout << "Enter 2 to calculate the area of a rectangle\n";
    cin >> choice;

    switch (choice) {
        case 1: {
            int radius, area_circle;
            cout << "Enter radius of the circle: ";
            cin >> radius;
            area_circle = 3.14 * radius * radius;
            cout << "Area of the circle: " << area_circle << endl;
            break;
        }
        case 2: {
            int length, width, area_rectangle;
            cout << "Enter length of the rectangle: ";
            cin >> length;
            cout << "Enter width of the rectangle: ";
            cin >> width;
            area_rectangle = length * width;
            cout << "Area of the rectangle: " << area_rectangle << endl;
            break;
        }
        default:
            cout << "Invalid choice! Please enter 1 or 2.\n";
            break;
    }

    return 0;
}


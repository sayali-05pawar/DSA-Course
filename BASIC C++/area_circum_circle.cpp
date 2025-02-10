#include <iostream>
using namespace std;

int main()
{
    float rad,area,circum;
    cout<<"Enter the radius of the circle: ";
    cin>>rad;
    area=3.14*rad*rad;
    circum=2*3.14*rad;
    cout<<"Area of the circel is "<<area<<endl;
    cout<<"Circumference of the circle is "<< circum;

    return 0;
}

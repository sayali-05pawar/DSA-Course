#include <iostream>
using namespace std;

int main()
{
    int num1,num2,num3;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;
    cout<<"Enter the third number: ";
    cin>>num3;
    if (num2<num1 && num3<num1)
    {
        cout<<"First number is greater ";
    }
    else if(num1<num2 && num3<num2)
    {
        cout<<"Second number is greater ";
    }
    else
    {
        cout<<"Third number is greater ";
    }
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int num1,num2,temp;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;
    temp = num1;
    num1 = num2;
    num2 = temp;
    cout<<"After swapping first number: "<<num1<<endl;
    cout<<"After swapping second number: "<<num2;
    return 0;
}

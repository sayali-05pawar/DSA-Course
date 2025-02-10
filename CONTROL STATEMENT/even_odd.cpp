#include <iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    
    if (num%2==0 && num>=2)
    {
        cout<<"Given number is even ";
    }
    else
    {
        cout<<"Given number is odd ";
    }
    return 0;
}

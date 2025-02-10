#include <iostream>
using namespace std;

int main()
{
    int p,time;
    float rate;
    cout<<"Enter the principal amount: ";
    cin>>p;
    cout<<"Enter the time period: ";
    cin>>time;
    cout<<"Enter the rate of interest: ";
    cin>>rate;
    cout<<"The simple interest for given info is: "<<(p*rate*time)/100;
    return 0;
}

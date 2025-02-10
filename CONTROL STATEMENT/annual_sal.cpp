#include <iostream>
using namespace std;

int main()
{
    float sal,tax;
    cout<<"Enter the annual salary: ";
    cin>>sal;
    if(sal <= 100000)
    {
        cout<<"NO TAX !!!"<<endl;
    }
    else if(100001<=sal && sal<=150000)
    {
        tax=(sal-100000)*10/100;
        cout<<"The rate of tax will be "<<tax<<endl;
    }
    else if(150001<=sal && sal<=250000)
    {
        tax=(sal-100000)*20/100+5000;
        cout<<"The rate of tax will be "<<tax<<endl;
    }
    else
    {
        tax=(sal-100000)*30/100+25000;
        cout<<"The rate of tax will be "<<tax<<endl;
    }
    cout<<"-----------THANK YOU-------------";
    return 0;
}

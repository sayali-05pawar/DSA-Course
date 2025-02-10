#include <iostream>
using namespace std;

int main()
{
    int num,res,i;
    cout<<"Enter a number for which the table should be provided: ";
    cin>>num;
    for(i=1;i<=10;i++)
    {
        res = num * i;
        cout<<num<<" x "<<i<<" = "<<res<<endl;
    }

    return 0;
}

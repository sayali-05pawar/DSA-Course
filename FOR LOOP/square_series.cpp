#include <iostream>
using namespace std;

int main()
{
    int num,res,i;
    cout<<"Enter number limit for series : ";
    cin>>num;
    for(i=1;i<=num;i++)
    {
        res = i * i;
        cout<<res<<"\t";
    }

    return 0;
}

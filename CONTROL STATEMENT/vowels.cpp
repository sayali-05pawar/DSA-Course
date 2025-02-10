#include <iostream>
using namespace std;

int main()
{
    char x;
    cout<<"Enter a character: ";
    cin>>x;
    
    if (x=='a' || x=='A' || x=='e' || x=='E' || x=='i' || x=='I' || x=='o' || x=='O' || x=='u' || x=='U')
    {
        cout<<"Given character is a VOWEL ";
    }
    else
    {
        cout<<"Given character is not a VOWEL ";
    }
    return 0;
}

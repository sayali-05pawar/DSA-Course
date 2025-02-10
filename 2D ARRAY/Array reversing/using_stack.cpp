/*Push each element of the array onto a stack.
Pop elements from the stack to form the reversed array.*/
#include <iostream>
using namespace std;

int data[10];
int top = 0;

class stack
{	
	public:
	stack()
	{
		top = -1;	
	}	
	void push(int no)
	{
		top ++;
		data[top] = no;
		cout<<no<<" is pushed into stack "<<endl;
	}
	int pop()
	{
		int no;
		no = data[top];
		top -- ;
		return no;	
	}
	bool isempty()
	{
		if(top == -1)
			return true;
		return false;
	}
	bool isfull()
	{
		if(top == 9)
			return true;
		return false;
	}
};
void display()
{
	cout<<"\nThe elements in the stack are: ";
	for(int i=0;i<=top;i++)
		cout<<data[i]<<'\t';
}

int main()
{
	stack s;
	int choice,num[100],i,size;
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"Enter array elememts: ";
    for(i=0;i<size;i++)
    {
        cin>>num[i];
    }
	for(i=0;i<size;i++)
    {
        s.push(num[i]);
    }
						
	display();
    cout << "\nAfter reversing: ";
    for (int i = 0; i < size; i++) {
        int poppedValue = s.pop();
        if (poppedValue != -1) {
            cout << poppedValue << " ";
        }
    }
    cout << endl; 
	return 0;
}
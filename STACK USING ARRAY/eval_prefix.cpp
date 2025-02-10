//Evaluation of PREFIX Expression 
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class stack
{
	public:
	char data[100];
	int top;
	
	stack()
	{
		top = -1;
	}
	void push(int c)
	{
		top++;
		data[top] = c;
	}
	int pop()
	{
		int no;
		no = data[top];
		top --;
		
		return no;	
	}	
	char get_top() //return the value present in stack
	{
		return data[top];
	}
	int isempty()
	{
		if (top == -1)
			return 1;
		
		return 0;
	}
};

int isop(char op) //check whether the string contain operator or not
{
	switch (op)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^': return 1;
	}
	return 0;
}

int cal(char op,int a,int b) 
{
	switch (op)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
		case '^': return pow(a,b);
	}
	return 0;
}

int main()
{
	char pre[100];
	char x;
	stack s1;
	int j = 0,k,op1,op2,res;
	
	cout<<"\nEnter a PREFIX EXPRESSION: ";
	cin>>pre;
	
	for(int i = strlen(pre)-1;i >= 0; i--)
	{
		x = pre[i];
		
		//if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' )
		if(isalpha(x)) //check whether it is letter/alphabet in-built function
		{
			cout<<"Enter the value of "<<x<<": ";
			cin>>k;
			s1.push(k);			
		}			
		else if(isop(x)) //check whether given string contain operator
		{
			op1 = s1.pop();
			op2 = s1.pop();
			res = cal(x,op1,op2);
				
			s1.push(res);
		}
	}
	
	cout<<"FINAL RESULT: "<<s1.pop();
		
	return 0;
}

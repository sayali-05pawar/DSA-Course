#include <iostream>
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
	void push(char c)
	{
		top++;
		data[top] = c;
	}
	char pop()
	{
		char c;
		c = data[top];
		top --;
		
		return c;	
	}	
	char get_top() //return the value present in stack //peek
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

int priority(char op) //check the priorities of the operator
{
	switch (op)
	{
		case '+':
		case '-': return 10;
		case '*':
		case '/': return 15;
		case '^': return 20;
	}
	return 0;
}

int main()
{
	char inf[10],post[10];
	char x;
	stack s1;
	int j = 0;
	
	cout<<"\nEnter a INFIX EXPRESSION: ";
	cin>>inf;
	
	for(int i = 0;i < strlen(inf); i++)
	{
		x = inf[i];
		
		//if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' )
		if(isalpha(x)) //check whether it is letter/alphabet in-built function
			post[j++] = x;
			
		else if(isop(x)) //check whether given string contain operator
		{
			while(priority (s1.get_top()) >= priority(x))
				post[j++] = s1.pop();
				
			s1.push(x);
		}
		
		else if(x == '(')
		{
			s1.push(x);
		}
		
		else if(x == ')')
		{
			while (s1.get_top() != '(')
				post[j++] = s1.pop();
				
			s1.pop();
		}
	}
	while(!s1.isempty())
	{
		post[j++] = s1.pop();
	}
	
	post[j] = '\0';
	cout<<"POSTFIX Expression: "<<post;
		
	return 0;
}

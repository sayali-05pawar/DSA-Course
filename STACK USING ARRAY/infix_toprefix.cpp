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
	char inf[100],pre[100];
	char x;
	stack s1;
	int j = 0;
	
	cout<<"\nEnter a INFIX EXPRESSION: ";
	cin>>inf;
	
	for(int i = strlen(inf)-1 ;i >= 0 ; i--)
	{
		x = inf[i];
		
		//if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' )
		if(isalpha(x)) //check whether it is letter/alphabet in-built function
			pre[j++] = x;
			
		else if(isop(x)) //check whether given string contain operator
		{
			while(priority (s1.get_top()) > priority(x))
				pre[j++] = s1.pop();
				
			s1.push(x);
		}
		
		else if(x == ')')
		{
			s1.push(x);
		}
		
		else if(x == '(')
		{
			while (s1.get_top() != ')')
				pre[j++] = s1.pop();
				
			s1.pop();
		}
	}
	while(!s1.isempty())
	{
		pre[j++] = s1.pop();
	}
	
	pre[j] = '\0';
	cout<<"PREFIX Expression: "<<strrev(pre); //in-built string reverse function
		
	return 0;
}

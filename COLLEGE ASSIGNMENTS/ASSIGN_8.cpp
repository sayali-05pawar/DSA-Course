/* Assignment No - 8
 Assignment Title - Write a program to convert infix expression to postfix, infix expression to prefix and evaluation of 
 postfix and prefix expression.*/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class stack1
{
    int top;
    char data[10];

    public:
    stack1()
    {
        top = -1;
    }
    
    bool isempty()
    {
       if(top == -1)
            return 1;

        return 0;

    }

    void push(char c)
    {
        top++;
        data[top] = c;
    }

    char pop()
    {
        char z;
        z = data[top];
        top--;

        return z;
    }

    char get_top()
    {
        return data[top];
    }
};

class stack2
{
    int top;
    int data[10];

    public:
    stack2()
    {
        top = -1;
    }

    bool isempty()
    {
       if(top == -1)
            return 1;

        return 0;

    }

    void push(int c)
    {
        top++;
        data[top] = c;
    }

    int pop()
    {
        int z;
        z = data[top];
        top--;

        return z;
    }

    char get_top()
    {
        return data[top];
    }
};

int isop(char op)
{
    switch (op)
    {
    case '+': 
    case '-':
    case '*':
    case '/':
    case '^': 
        return 1;
    }
    return 0;
}

int priority(char op)
{
    switch (op)
    {
    case '+': 
    case '-': return 1;
    case '*':
    case '/': return 2;
    case '^': return 3;
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

void infix_to_post()
{
    char infix[10],post[10];
    stack1 s1;
    int j=0;

    cout<<"Enter the INFIX EXPRESSION: ";
    cin>>infix;

    for(int i=0;i<strlen(infix);i++)
    {
        char x = infix[i];
        if(x >= 'a' && x<='z' || x >= 'A' && x <= 'Z')
        {
            post[j++] = x;
        }
        else if(isop(x))
        {
            while(priority(s1.get_top()) >= priority(x))
            {
                post[j++] = s1.pop();
            }
            s1.push(x);
        }
        else if(x == '(')
        {
            s1.push(x);
        }
        else if(x == ')')
        {
            while(s1.get_top() != '(')
            {
                post[j++] = s1.pop();
            }
            s1.pop();
        }
    }
    while(!s1.isempty())
        {
            post[j++] = s1.pop();
        }

        post[j] = '\0';
        cout<<"POSTFIX EXPRESSION: "<<post;
}

void infix_to_pre()
{
    char infix[10],pre[10];
   int j = 0;
   stack1 s2;

   cout<<"Enter the INFIX EXPRESSION: ";
   cin>>infix;

   for(int i = strlen(infix)-1; i>=0 ;i--)
   {
        char x = infix[i];

        if(x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')
        {
            pre[j++] = x;
        }
        else if(isop(x))
        {
            while(priority(s2.get_top()) > priority(x))
                pre[j++] = s2.pop();

            s2.push(x);
        }
        else if(x == ')')
        {
            s2.push(x);
        }
        else if(x == '(')
        {
            while(s2.get_top() != ')')
                pre[j++] = s2.pop();

            s2.pop();
        }
   }
    while(!s2.isempty())
    {
        pre[j++] = s2.pop();
    }

    pre[j] ='\0';
    cout<<"PREFIX EXPRESSION: "<<strrev(pre);
}

void eval_post()
{
    char post[10];
   int j=0,k,op1,op2;
   char x;
   stack2 s3;

   cout<<"Enter a POSTFIX EXPRESSION: ";
   cin>>post;
    
   for(int i=0 ; i<strlen(post) ;i++)
   {
        x=post[i];
        if(x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')
        {
            cout<<"Enter value for "<<x<<": ";
            cin>>k;

            s3.push(k);
        }
        else if(isop(x))
        {
            op2 = s3.pop();
            op1 = s3.pop();

            s3.push(cal(x,op1,op2));
        }
   }

    cout<<"Postfix Evalution: "<<s3.pop();
}

int main()
{
   char pre[10];
   int j=0,k,op1,op2;
   char x;
   stack2 s4;

   cout<<"Enter a PREFIX EXPRESSION: ";
   cin>>pre;
    
   for(int i=strlen(pre)-1; i>=0 ;i--)
   {
        x=pre[i];
        if(x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')
        {
            cout<<"Enter value for "<<x<<": ";
            cin>>k;

            s4.push(k);
        }
        else if(isop(x))
        {
            op1 = s4.pop();
            op2 = s4.pop();

            s4.push(cal(x,op1,op2));
        }
   }

    cout<<"Postfix Evalution: "<<s4.pop();
    return 0;
}
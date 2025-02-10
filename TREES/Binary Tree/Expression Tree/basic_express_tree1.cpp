// Expression Tree using POSTFIX Expression
//traverse using temp 
#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

class Node {
public:
    char data;
    Node* left, * right;

    Node(char value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class stack {
public:
    Node* data[100];
    int top;

    stack() {
        top = -1;
    }
    void push(Node* c) {
        top++;
        data[top] = c;
    }
    Node* pop() {
        Node* no;
        no = data[top];
        top--;

        return no;
    }
    Node* get_top() // return the value present in stack
    {
        return data[top];
    }
    int isempty() {
        if (top == -1)
            return 1;

        return 0;
    }
};

int isop(char op) // check whether the string contain operator or not
{
    switch (op) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^': return 1;
    }
    return 0;
}

int cal(char op, int a, int b)
{
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    }
    return 0;
}

class express_tree {
public:
    Node* temp, * nnode, * root;
    char post[100];
    char x;
    stack s1;

    express_tree() {
        temp = NULL;
        nnode = NULL;
        root = NULL;
    }

    void create() {
        cout << "\nEnter a POSTFIX EXPRESSION: ";
        cin >> post;

        for (int i = 0; i < strlen(post); i++) {
            x = post[i];

            if (isalpha(x)) // check whether it is letter/alphabet in-built function
            {
                temp = new Node(x);
                s1.push(temp);
            }
            else if (isop(x)) // check whether given string contain operator
            {
                temp = new Node(x);
                temp->right = s1.pop();
                temp->left = s1.pop();

                s1.push(temp);
            }
        }

        root = s1.pop(); // get the root node
    }

    void inorder(Node* temp) // recursion
    {
        if (temp != NULL) {
            inorder(temp->left);
            cout << temp->data ;
            inorder(temp->right);
        }
    }

    void preorder(Node* temp)
    {
        if (temp != NULL) {
            cout << temp->data ;
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    void postorder(Node* temp)
    {
        if (temp != NULL) {
            postorder(temp->left);
            postorder(temp->right);
            cout << temp->data;
        }
    }
};

int main() 
{
    express_tree e;
    e.create();
    cout << "IN-FIX: ";
    e.inorder(e.root);
    cout << endl;
    cout << "PRE-FIX: ";
    e.preorder(e.root);
    cout << endl;
    cout << "POST-FIX: ";
    e.postorder(e.root);
    cout << endl;
    return 0;
}

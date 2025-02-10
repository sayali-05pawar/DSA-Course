//Create and display tree using non-recursive or using stack
#include <iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *left,*right;
	
	Node()
	{
		data = 0;
		left = NULL;
		right = NULL;	
	}	
};

class stack
{
	Node *data[100];
	int top = 0;
	public:
	stack()
	{
		top = -1;	
	}	
	void push(Node *no)
	{
		top ++;
		data[top] = no;
	}
	Node *pop()
	{
		Node *no;
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
		if(top == 99)
			return true;
		return false;
	}	
};

class GBT
{
	public:
	Node *root;
	
	GBT()
	{
		root = NULL;	
	}	 
	
	void create()
	{
		char side;
		Node *nnode,*temp;
		int terms;
		
		cout<<"Enter how many terms you have to insert: ";
		cin>>terms;
		for(int i = 1;i<=terms;i++)
		{
			nnode = new Node;
			cout<<"Enter a data: ";
			cin>>nnode -> data;
			
			if(root == NULL)
				root = nnode;
			else
			{
				temp = root;
				while (1)
				{
					cout<<"Enter (l/r) side of "<<temp->data<<": ";
					cin>>side;
					
					if(side == 'l')
					{
						if(temp->left == NULL)
						{
							temp->left = nnode;
							break;
						}
						else
							temp = temp->left;
					}
					else
					{
						if(temp->right == NULL)
						{
							temp->right = nnode;
							break;
						}
						else
							temp = temp->right;
					}
				}
			}
		}
	}
	
	void inorder() //using stack
	{
		stack s1;
		Node *temp;
		
		temp = root;
		do
		{
			s1.push(temp);
			temp = temp->left;
		}while(temp != NULL);
		
		while(!s1.isempty())
		{
			temp = s1.pop();
			cout<<temp->data<<'\t';
			if(temp->right != NULL)
			{
				temp = temp->right;
				
				while(temp != NULL)
				{
					s1.push(temp);
					temp = temp->left;
				}
			}
		}
	}
	
	void preorder()
	{
		stack s1;
		Node *temp;
		
		temp = root;
		do
		{
			s1.push(temp);
			cout<<temp->data<<'\t';
			temp = temp->left;
		}while(temp != NULL);
		
		while(!s1.isempty())
		{
			temp = s1.pop();
			
			if(temp->right != NULL)
			{
				temp = temp->right;
				
				while(temp != NULL)
				{
					cout<<temp->data<<'\t';
					s1.push(temp);
					temp = temp->left;
				}
			}
		}	
	}
	
	void postorder() //wrong logic
	{
		Node *temp = root;
		stack s1,s2;
		
		s1.push(temp);
		
		while(!s1.isempty())
		{
			temp = s1.pop();
			s2.push(temp);
			
			if(temp->left != NULL)
				s1.push(temp->left);
			if(temp->right != NULL)
				s1.push(temp->right);
				
			while(!s2.isempty())
			{
				temp = s2.pop();
				cout<<temp->data<<'\t';
			}
		}
	}
};

int main()
{
	GBT g;
    g.create();
    cout << "IN-ORDER TRAVERSAL: ";
    g.inorder();
    cout << endl;
    cout << "PRE-ORDER TRAVERSAL: ";
    g.preorder();
    cout << endl;
    cout << "POST-ORDER TRAVERSAL: ";
    g.postorder();
    cout << endl;
    
	return 0;
}

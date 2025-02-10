//Create and display tree using recursion
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

class BST
{
	public:
	Node *root;
	
	BST()
	{
		root = NULL;	
	}	 
	
	void create()
	{
		int terms;
		Node *nnode,*temp;
		
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
					if(temp->data > nnode->data)
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
	
	void inorder(Node *temp) //recursion
	{
		if(temp!=NULL)
		{
			inorder(temp->left);
			cout<<temp->data<<'\t';
			inorder(temp->right);
		}
	}
	
	void preorder(Node *temp)
	{
		if(temp!=NULL)
		{
			cout<<temp->data<<'\t';
			preorder(temp->left);
			preorder(temp->right);
		}	
	}
	
	void postorder(Node *temp)
	{
		if(temp!=NULL)
		{
			postorder(temp->left);
			postorder(temp->right);
			cout<<temp->data<<'\t';
		}
	}
};

int main()
{
	BST g;
    g.create();
    cout << "IN-ORDER TRAVERSAL: ";
    g.inorder(g.root);
    cout << endl;
    cout << "PRE-ORDER TRAVERSAL: ";
    g.preorder(g.root);
    cout << endl;
    cout << "POST-ORDER TRAVERSAL: ";
    g.postorder(g.root);
    cout << endl;
    
	return 0;
}

//Operations
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

class BST
{
	public:
	Node *root;
	
	GBT()
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
	
	/*SEARCHING ELEMENT IN GIVEN TREE
	bool issearch(int no) 				//without recursion
	{
		Node *temp = root;
		do{
			if(temp->data == no)
				return true;
			
			else if(temp->data > no)
				temp = temp->left;
				
			else
				temp = temp->right;
		}while(temp != NULL);
		
		return false;
	}*/
	
	bool issearch(Node *temp,int no) 		//using recursion
	{
		if(temp != NULL)
		{
			if(temp->data == no)
				return true;
			
			else if(temp->data > no)
				return issearch(temp->left,no);
				
			else
				return issearch(temp->right,no);
		}
	}
	
	//FINDING MAXIMUM FROM GIVEN BST
	void max() 							//without recursion
	{
		Node *temp = root;
		
		while(temp->right != NULL)
			temp = temp -> right;
			
		cout<<"\nMaximum: "<<temp->data;
	}
	
	//FINDING MINIMUM FROM GIVEN BST
	void min()  						//without recursion
	{
		Node *temp = root;
		
		while(temp->left != NULL)
			temp = temp -> left;
			
		cout<<"\nMinimum: "<<temp->data;
	}
	
	//DISPLAY LEAF NODES
	void dis_leafnode(Node *temp)
	{
		if (temp != NULL)
		{
			dis_leafnode(temp->left);
			if (temp->left == NULL && temp->right == NULL)
				cout<<temp->data<<'\t';
			dis_leafnode(temp->right);
		}
	}
	
	/*void dis_leafnode() 		//using stack,without recursion
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
			if (temp->left == NULL && temp->right == NULL)
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
	}*/
	
	//COUNT THE LEAF NODES
	int leaf_count(Node *temp)  		//using recursion
	{
		if(temp != NULL)
		{
			if (temp->left == NULL && temp->right == NULL)
				return 1;
				
			return leaf_count(temp->left) + leaf_count(temp->right);
		}
		return 0;
	}
	
	//DISPLAY NODE WITH DEGREE 1;
	void dis_node_deg1(Node *temp)
	{
		if (temp != NULL)
		{
			dis_node_deg1(temp->left);
			if((temp->left == NULL && temp->right != NULL) || (temp->right == NULL && temp->left != NULL))
				cout<<temp->data<<'\t';
			dis_node_deg1(temp->right);
		}
	}
	
	//COPY OF TREE
	Node *copy(Node *temp)
	{
		Node *nnode = NULL;
		
		if(temp != NULL)
		{
			nnode = new Node;
			nnode->data = temp->data;
			nnode->left = copy(temp->left);
			nnode->right = copy(temp->right);
		}
		return nnode;
	}
	
	//MIRROR OF TREE
	Node *mirror(Node *temp)
	{
		Node *nnode = NULL;
		
		if(temp != NULL)
		{
			nnode = new Node;
			nnode->data = temp->data;
			nnode->left = mirror(temp->right);
			nnode->right = mirror(temp->left);
		}
		return nnode;
	}
};

int main()
{
	BST g; int num;
    g.create();
    /*cout << "IN-ORDER TRAVERSAL: ";
    g.inorder(g.root);
    cout << endl;
    cout << "PRE-ORDER TRAVERSAL: ";
    g.preorder(g.root);
    cout << endl;
    cout << "POST-ORDER TRAVERSAL: ";
    g.postorder(g.root);
    cout << endl;*/
    
    /*cout<<"Enter the number to be search: ";
    cin>>num;
    if(g.issearch(g.root,num))
    	cout<<"\nNumber found!!!";
    else
    	cout<<"\nNumber not found ";
   
    g.max();
    g.min();
    
    cout<<"\nThe leaf node: ";
    g.dis_leafnode(g.root);
    
    cout<<"\nTotal leaf nodes: "<<g.leaf_count(g.root) ;
    
    cout<<"\nDisplay nodes with degree 1: ";
    g.dis_node_deg1(g.root);*/
    
     // Display original BST
    cout << "Original BST:" << endl;
    cout << "In-order traversal: ";
    g.inorder(g.root);
    cout << endl;
    
    // Create a copy of the BST
    Node *copyRoot = g.copy(g.root);
    cout << "Copy of BST:" << endl;
    cout << "In-order traversal: ";
    g.inorder(copyRoot);
    cout << endl;
    
    // Create a mirror of the BST
    Node *mirrorRoot = g.mirror(g.root);
    cout << "Mirror of BST:" << endl;
    cout << "In-order traversal: ";
    g.inorder(mirrorRoot);
    cout << endl;
    
    
	return 0;
}

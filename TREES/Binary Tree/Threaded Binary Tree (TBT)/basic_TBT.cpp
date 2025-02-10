//Create and display tree using recursion
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    int lt, rt; // left thread, right thread

    Node()
    {
        data = 0;
        lt = 1; // left thread
        rt = 1; // right thread
        left = NULL;
        right = NULL;
    }
};

class TBT
{
	public:
    Node *root;
    Node *dummy;

    TBT()
    {
        root = NULL;
        dummy = new Node;
        dummy->left = dummy;
        dummy->right = dummy;
    }	 
	
	void create()
	{
		int terms;
		Node *nnode,*temp,*dummy;
		
		cout<<"Enter how many terms you have to insert: ";
		cin>>terms;
		for(int i = 1;i<=terms;i++)
		{
			nnode = new Node;
			cout<<"Enter a data: ";
			cin>>nnode -> data;
			
			if(root == NULL)
			{
				root = nnode;
				root -> right = dummy;
				root -> left = dummy;
				root -> rt = 1;
				root -> lt = 1;
			}
			else
			{
				temp = root;
				while (1)
				{
					if(temp->data > nnode->data)
					{	
							if(temp->lt == 1)
							{
								nnode->left = temp -> left;
								nnode -> lt = temp -> lt;
								temp->left = nnode;
								temp -> lt =0;
								break;
							}
							else
								temp = temp->left;
					}
					else
					{
						if(temp->rt == 1)
						{
							nnode->right = temp ->right;
							nnode -> rt = temp -> rt;
							temp->right = nnode;
							temp -> rt =0;
							break;
						}
						else
							temp = temp->right;
					}
				}
			}
		}
	}
	
	/*void inorder(Node *temp) // recursion
	{
   		 if (temp!= dummy)
    	{
    	    if (temp->lt == 0)
    	        inorder(temp->left);

        	cout << temp->data << '\t';

        	if (temp->rt == 0)
        	    inorder(temp->right);
    	}
	}*/
	
	void inorder()
	{
		Node *temp = root;
		int flag = 1;
		do
		{
			while (temp->lt==0 && flag==1)
			{
				temp = temp->left;
			}
			cout<<temp->data<<'\t';
			
			if(temp->rt==0) //child present
				flag=1;
			else   			//there is thread
				flag=0;
				
			temp = temp->right;
		}
		while(temp!=dummy);
	}
	
	void preorder()
	{
		Node *temp=root;
		
		do{
			while(temp->lt != 1)
			{
				cout<<temp->data<<'\t';
				temp = temp->left;
			}
			if(temp->lt==1)
			{
				cout<<temp->data<<'\t';
				
				if(temp->rt==0)
				{
					temp = temp->right;
				}
				else
				{
					while(temp->rt==1 && temp!=dummy)
					{
						temp = temp->right;
					}
					temp = temp->right;
				}
			}
		}while(temp!=dummy);
	}
	
};

int main()
{
	TBT t;
    t.create();
    cout << "IN-ORDER TRAVERSAL: ";
    t.inorder();
    cout << endl;
    cout << "PRE-ORDER TRAVERSAL: ";
    t.preorder();
    
	return 0;
}

#include <iostream>
using namespace std;


class Node
{
	public:
	int coeff,expo; 
	Node *next; 
	Node() 
	{
		coeff = 0;
		expo = 0;
		next = NULL;	
	}	
};

class Polynomial
{
	Node *start;  
				
	public:
	Polynomial() 
	{
		start = NULL;
	}
	
	void create() 
	{
		Node *nnode; 
		Node *temp;
		int n;
		cout<<"Enter the terms: ";
		cin>>n;
		do{
			nnode = new Node; 
			cout<<"Enter the co-efficient: ";
			cin>>nnode -> coeff;
			cout<<"Enter the power of exponent: ";
			cin>>nnode -> expo;
			
			if(start == NULL) 
			{
				start = nnode;
			}
			else 
			{
				temp = start;
				while (temp -> next != NULL)
					temp = temp -> next;
				temp -> next = nnode;
			}
			n--;
		}
		while (n>0);
	}
	
	void insert(Node *nnode)
	{
		Node *temp;
		
		if(start == NULL) 
			{
				start = nnode;
			}
			else 
			{
				temp = start;
				while (temp -> next != NULL)
					temp = temp -> next;
				temp -> next = nnode;
			}
	}
	
	void display()
	{
		Node *temp;
		cout<<"\nThe store numbers are: ";
		for (temp = start;temp != NULL;temp = temp -> next)
		{
			cout<<temp -> coeff<<"x ^"<<temp -> expo<<"+";
		}
		cout<<"\b\b";
	}
	
	void add (Polynomial p1,Polynomial p2)
	{
		Node *t1,*t2,*temp,*nnode;
		
		t1 = p1.start;
		t2 = p2.start;
		
		while (t1 != NULL && t2 != NULL)
		{
			nnode = new Node;
			if(t1 -> expo > t2 -> expo)
			{
				nnode -> expo = t1 -> expo;
				nnode -> coeff = t1 -> coeff;
				t1 = t1 -> next;
			}
			else if(t2 -> expo > t1 -> expo)
			{
				nnode -> expo = t2 -> expo;
				nnode -> coeff = t2 -> coeff;
				t2 = t2 -> next;
			}
			else if(t1 -> expo == t2 -> expo)
			{
				nnode -> expo = t1 -> expo;
				nnode -> coeff = t1 -> coeff + t2 -> coeff;
				t1 = t1 -> next;
				t2 = t2 -> next;
			}  
			insert(nnode);
		}
		
		while(t1 != NULL)
		{
			nnode = new Node;
			nnode -> expo = t1 -> expo;
			nnode -> coeff = t1 -> coeff;
			t1 = t1 -> next;
			insert(nnode);
		}
		
		while(t2 != NULL)
		{
			nnode = new Node;
			nnode -> expo = t2 -> expo;
			nnode -> coeff = t2 -> coeff;
			t2 = t2 -> next;
			insert(nnode);
		}
		
		cout<<"\nAddition :";
		}
};

int main()
{
	Polynomial p1,p2,p3;
	p1.create();
	p2.create();
	
	
	p3.add (p1,p2);
	p3.display();
	return 0;
}

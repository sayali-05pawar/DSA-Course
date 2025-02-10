//showing matrix in the form of 0,1....
//Enter vertex,traversal in integer 0,1..... 
#include <iostream>
using namespace std;

class Queue
{
	int data[10];
	int front,rear;
	
	public:
	Queue()
	{
		rear = -1;
		front = 0;	
	}
	
	void enque(int no)
	{
		if (isfull())
        {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
		rear++;
		data[rear] = no;
	}	
	
	int deque()
	{
		if (isempty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
		int n;
		n = data[front];
		front++;
		
		return n;
	}
	
	int isempty()
	{
		if(front == rear+1)
			return 1;
		else
			return 0;
	}
	
	int isfull()
	{
		if(rear == 9) //rear = size-1
			return 1;
		else 
			return 0;
	}
	
};

class Graph
{
	public:
	int vertex,edges;
	int G[10][10];
	int visit[10];
	
	Graph(int v)
	{
		vertex = v;
		for(int i=0;i<vertex;i++)
			for(int j=0;j<vertex;j++)
				G[i][j]=0;	
	}
	
	void initvisit()
	{
		for(int i=0;i<vertex;i++)
			visit[i]=0;	
	}	
	
	void create()
	{
		int sv,ev,w; //start vertex,end vertex,weight
		int type;
		
		cout<<"\nEnter Edges: ";
		cin>>edges;
		
		cout<<"\nMENU: "
			<<"\n1.Undirected Unweighted Graph "
			<<"\n2.Undirected Weighted Graph"
			<<"\n3.Directed Unweighted Graph "
			<<"\n4.Directed Weighted Graph"
			<<"\n----------------------------------------------"
			<<"\nEnter the type: ";
		cin>>type;
		
		for(int k=1;k<=edges;k++)
		{
			cout<<"\nEnter a Start & End Vertex of Edge: ";
			cin>>sv>>ev;
			
			if(type==1)
			{
				G[sv][ev] = 1;
				G[ev][sv] = 1;
			}
			else if(type==2)
			{
				cout<<"\nEnter a Weight: ";
				cin>>w;
				G[sv][ev] = w;
				G[ev][sv] = w;
			}
			else if(type==3)
			{
				G[sv][ev] = 1;
			}
			else if(type==4)
			{
				cout<<"\nEnter a Weight: ";
				cin>>w;
				G[sv][ev] = w;
			}
		}
	}
	
	void show()
	{
		cout<<"\nGraph is: ";
		for(int i=0;i<vertex;i++)
		{
			cout<<"\n";
			for(int j=0;j<vertex;j++)
				cout<<G[i][j]<<'\t';
		}
	}
	
	void DFS(int v) //can be done using stack also here recursion is used
	{
		cout<<v;
		visit[v]=1;
		
		for(int i=0;i<vertex;i++)
		{
			if(G[v][i] != 0 && visit[i] == 0)
				DFS(i);
		}
	}
	
	void BFS(int v) //using queue
	{
		initvisit();
		Queue q1;
		
		q1.enque(v);
		visit[v]=1;
		
		while(!q1.isempty())
		{
			v = q1.deque();
			cout<<v;
			for(int i=0;i<vertex;i++)
			{
				if(G[v][i] != 0 && visit[i] == 0)
				{
					q1.enque(i);
					visit[i]=1;
				}
			}
		}
	}
};

int main()
{
	int v;
	cout<<"\nEnter a Vertex: ";
	cin>>v;
	Graph g(v);
	g.create();
	g.show();
	
	g.initvisit();
	cout<<"\nEnter a start vertex for DFS Traversal: ";
	cin>>v;
	cout<<"\nDFS Traversal: ";
	g.DFS(v);
	
	cout<<"\nEnter a start vertex for BFS Traversal: ";
	cin>>v;
	cout<<"\nBFS Traversal: ";
	g.BFS(v);
	
	return 0;
}

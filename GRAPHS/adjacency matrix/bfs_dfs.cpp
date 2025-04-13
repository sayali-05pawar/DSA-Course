#include <iostream>
using namespace std;

class queue
{
	int data[10];

int rear , front ;

	public:
	queue()
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

void BFS(int G[][7],int start,int n)
{
    int i=start;
    queue q;
    int visited[7]={0};

    cout<<i<<" ";
    visited[i]=1;
    q.enque(i);

    while(!q.isempty())
    {
        i=q.deque();
        for(int j=1;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                cout<<j<<" ";
                visited[j]=1;
                q.enque(j);
            }
        }
    }
}

void DFS(int G[][7],int start,int n)
{
    static int visited[7]={0};

    if(visited[start]==0)
    {
        cout<<start<<" ";
        visited[start]=1;

        for(int j =1;j<n;j++)
        {
            if(G[start][j]==1 && visited[j]!=1)
            {
                DFS(G,j,n);
            }
        }
    }
}

int main()
{
    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};

BFS(G,1,7);
cout<<endl;
DFS(G,1,7);

return 0;
}
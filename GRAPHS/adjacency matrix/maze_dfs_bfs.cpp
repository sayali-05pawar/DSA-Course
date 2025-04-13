/*Consider the scenario of a maze. The maze is represented as a grid of cells, where each cell
can be either open or blocked. Each cell in the maze represents a vertex. The goal is to find a
path from the starting point to the goal within a given maze using DFS and BFS.*/
#include <iostream>
using namespace std;

class queue
{
    int data[100];
    int rear,front;

    public:
    queue()
    {
        rear = -1;
        front = 0;
    }

    bool isfull()
    {
        if(rear == 99) return true;
        else return false;
    }

    bool isempty()
    {
        if(front == rear+1) return true;
        else return false;
    }

    void enqueue(int no)
    {
        if(isfull())
            cout<<"Queue is full.Cannot enqueue.";
        else
        rear++;
        data[rear] = no;
    }

    int dequeue()
    {
        int z;
        if(isempty())
            cout<<"Queue is empty.Cannot dequeue.";
        else
        {
        z = data[front];
        front++;
        }
        return z;
    }
};

void BFS(int G[][7],int i,int n)
{
    queue q;
    int visited[7] = {0};
    cout<<i<<" ";
    visited[i] = 1;
    q.enqueue(i);

    while(!q.isempty())
    {
        i=q.dequeue();
        for(int j=1;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                cout<<j<<" ";
                visited[j]=1;
                q.enqueue(j);
            }
        }
    }
}

void DFS(int G[][7],int i,int n)
{
    static int visited[7] = {0};
    if(visited[i] == 0)
    {
        cout<<i<<" ";
        visited[i] = 1;

        for(int v=1; v<n; v++)
        {
            if(G[i][v]==1 && visited[v] == 0)
            {
                DFS(G,v,n);
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

cout<<"BFS Traversal:- ";
BFS(G,1,7);
cout<<endl;
cout<<"DFS Traversal:- ";
DFS(G,1,7);

return 0;
}
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 6
#define INF INT_MAX

class DijkstraSCM
{ 
    vector <vector<int>> graph;
    vector <string> supplyChains;

    public:
    DijkstraSCM(vector<vector<int>> &intputgraph, vector<string> names)
    {
        graph = intputgraph;
        supplyChains = names;
    }

    int findMinDistance(vector<int> &dist,vector<bool> &visited)
    {
        int minValue = INF;
        int minIndex = -1;

        for(int i=0; i<V; i++)
        {
            if(!visited[i] && dist[i] < minValue)
            {
                minValue = dist[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

    void ShortestPathDistance(int src)
    {
        vector<int> parent(V,-1);
        vector<bool> visited(V,false);
        vector<int> dist(V,INF);

        dist[src] = 0;

        for(int count=0; count<V-1; count++)
        {
            int u = findMinDistance(dist,visited);
            visited[u] = true;

            dist[src] = 0;

            for(int v=0; v<V; v++)
            {
                if(!visited[v] && graph[u][v] != 0 && dist[u] != INF && (dist[u]+graph[u][v] < dist[v]))
                {
                    dist[v] = graph[u][v];
                    parent[v] = u;
                }
            }

        }

        cout << "Shortest Transportation Path from Source (" << supplyChains[src] << "):\n";
        for (int i = 0; i < V; i++) {
            cout << "To " << supplyChains[i] << " - Distance: " << dist[i]<<"\n";
        }
    }

};

int main() {
    // Adjacency matrix representing transportation costs between locations
    vector<vector<int>> supplyChainGraph = {
        {0, 163, 0, 40, 150, 0}, // Supplier
        {163, 0, 50, 0, 0, 120},  // Warehouse
        {0, 50, 0, 40, 15, 0},  // Distribution Center 1
        {40, 0, 40, 0, 65, 0},  // Distribution Center 2
        {150, 0, 15, 65, 0, 51},// Retail Store 1
        {0, 120, 0, 0, 51, 0}    // Retail Store 2
    };

    // Names corresponding to locations
    vector<string> locationNames = {
        "Supplier", "Warehouse", "Distribution Center 1", 
        "Distribution Center 2", "Retail Store 1", "Retail Store 2"
    };

    DijkstraSCM scm(supplyChainGraph, locationNames);
    int source = 0; // Start from "Supplier"
    scm.ShortestPathDistance(source);

    return 0;
}
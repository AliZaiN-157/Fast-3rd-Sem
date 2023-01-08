#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph
{
    int numVertices;    // Number of vertices in the graph
    vector<int>* adj;   // Pointer to an array containing adjacency lists

    // A recursive function used by DFS
    void DFSUtil(int vertex, vector<bool>& visited)
    {
        // Mark the current node as visited and print it
        visited[vertex] = true;
        cout << vertex << " ";

        // Recurse for all the vertices adjacent to this vertex
        for (int i = 0; i < adj[vertex].size(); ++i)
            if (!visited[adj[vertex][i]])
                DFSUtil(adj[vertex][i], visited);
    }

public:
    // Constructor
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adj = new vector<int>[numVertices];
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    // DFS traversal of the vertices reachable from vertex
    void DFS(int vertex)
    {
        // Mark all the vertices as not visited
        vector<bool> visited(numVertices, false);

        // Call the recursive helper function to print DFS traversal
        DFSUtil(vertex, visited);
    }
};



// Driver Code

int main()
{
	// Create a graph given in the above diagram
	Graph g(6);
	g.addEdge(0, 2);
	g.addEdge(0, 1);
	g.addEdge(0, 5);
	g.addEdge(1, 0);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 2);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 2);
	g.addEdge(4, 3);
	g.addEdge(5, 0);
	g.addEdge(5, 3);
	
	g.DFS(3);

	return 0;
}



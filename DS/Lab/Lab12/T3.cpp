#include <iostream>
#include <list>

using namespace std;

class Graph
{
	int V;    // No. of vertices
	list<int>* adj;    // Pointer to an array containing adjacency lists
public:
	Graph(int V);  // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	void BFS(int s);  // prints BFS traversal from a given source s
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	// 'i' will be used to get all adjacent vertices of a vertex
	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it visited
		// and enqueue it
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

// Driver program to test methods of graph class
int main()
{
	Graph G(7);
	G.addEdge(0, 2);
	G.addEdge(1, 2);
	G.addEdge(5, 6);
	G.addEdge(3, 1);
	G.addEdge(3, 3);
	G.addEdge(3, 5);
	G.addEdge(1, 6);
	G.addEdge(2, 4);
	G.addEdge(1, 3);
	G.addEdge(5, 4);
	G.BFS(0);
}

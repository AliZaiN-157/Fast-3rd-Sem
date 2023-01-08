#include <iostream>
#include <vector>

using namespace std;

// driver code to print the adjacent list of each vertex

class Graph
{
	int V; // No. of vertices

	// Pointer to an array containing adjacency lists
	vector<int>* adj;
	
public:
	Graph(int V) { // Constructor
		this->V = V;
		adj = new vector<int>[V];
	}
	void addEdge(int v, int w) { // function to add an edge to graph
		adj[v].push_back(w); // Add w to v’s list.
		adj[w].push_back(v); // Add v to w’s list.
	} 
	void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\n Adjacency list of vertex "
				<< v << "\n head ";
			for (auto x : adj[v])
				cout << "-> " << x;
			cout << endl;
		}
	}
};

// Driver code

int main()
{
	// create the graph given in above figure
	int V = 5;
	Graph g(V);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	g.printGraph();

	return 0;
}


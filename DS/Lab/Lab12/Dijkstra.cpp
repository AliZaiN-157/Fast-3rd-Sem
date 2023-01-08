// Dijkstra algorithm for shortest path in a graph

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Graph class
class Graph {
private:
	// Adjacency list
	unordered_map<int, vector<pair<int, int>>> adjList;
	// Number of vertices
	int numVertices;
public:
	// Constructor
	Graph(int numVertices) {
		this->numVertices = numVertices;
	}
	// Add edge
	void addEdge(int u, int v, int w) {
		adjList[u].push_back(make_pair(v, w));
	}
	// Dijkstra algorithm
	void dijkstra(int source) {
		// Distance vector
		vector<int> dist(numVertices, INT_MAX);
		// Set distance of source to 0
		dist[source] = 0;
		// Set to keep track of vertices included in shortest path tree
		unordered_set<int> sptSet;
		// Find shortest path for all vertices
		for (int count = 0; count < numVertices - 1; count++) {
			// Pick the minimum distance vertex from the set of vertices not yet processed
			int u = minDistance(dist, sptSet);
			// Add the picked vertex to the shortest path tree
			sptSet.insert(u);
			// Update dist value of the adjacent vertices of the picked vertex
			for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
				int v = it->first;
				int weight = it->second;
				if (!sptSet.count(v) && dist[u] != INT_MAX && dist[u] + weight < dist[v])
					dist[v] = dist[u] + weight;
			}
		}
		// Print shortest distances stored in dist
		printSolution(dist);
	}
	// Find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
	int minDistance(vector<int> dist, unordered_set<int> sptSet) {
		// Initialize min value
		int min = INT_MAX, minIndex;
		for (int v = 0; v < numVertices; v++)
			if (sptSet.count(v) == 0 && dist[v] <= min)
				min = dist[v], minIndex = v;
		return minIndex;
	}
	// Print the constructed distance array
	void printSolution(vector<int> dist) {
		cout << "Vertex Distance from Source" << endl;
		for (int i = 0; i < numVertices; i++)
			cout << i << " " << dist[i] << endl;
	}
};

int main() {
	// Create a graph
	Graph g(9);
	// Add edges
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);
	// Run Dijkstra algorithm
	g.dijkstra(0);
	return 0;
}
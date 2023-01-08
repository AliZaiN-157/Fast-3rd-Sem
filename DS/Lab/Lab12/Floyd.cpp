// Floyd Warshall Algorithm 

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Function to print the shortest distance matrix
void printSolution(vector<vector<int>> dist, int V)
{
	cout << "The following matrix shows the shortest distances"
		" between every pair of vertices" << endl;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == 9999)
				cout << "INF" << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

// Function to run Floyd Warshall Algorithm
void floydWarshall(vector<vector<int>> graph, int V)
{
	// dist[][] will be the output matrix that will finally
	// have the shortest distances between every pair of vertices
	vector<vector<int>> dist(V, vector<int>(V));

	// Initialize the solution matrix same as input graph matrix.
	// Or we can say the initial values of shortest distances
	// are based on shortest paths considering no intermediate
	// vertex.
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	// Add all vertices one by one to the set of intermediate
	// vertices.
	// ---> Before start of a iteration, we have shortest
	// distances between all pairs of vertices such that
	// the shortest distances consider only the vertices in
	// set {0, 1, 2, .. k-1} as intermediate vertices.
	// ----> After the end of a iteration, vertex no. k is
	// added to the set of intermediate vertices and the
	// set becomes {0, 1, 2, .. k}
	for (int k = 0; k < V; k++)
	{
		// Pick all vertices as source one by one
		for (int i = 0; i < V; i++)
		{
			// Pick all vertices as destination for the
			// above picked source
			for (int j = 0; j < V; j++)
			{
				// If vertex k is on the shortest path from
				// i to j, then update the value of dist[i][j]
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	printSolution(dist, V);
}

// Driver code

int main()
{
	// Number of vertices in the graph
	int V = 4;

	// Let us create the following weighted graph
	vector<vector<int>> graph = { { 0, 8, 9999, 1 },
								{ 9999, 0, 1, 9999 },
								{ 4, 9999, 0, 9999 },
								{ 9999, 2, 9, 0 }
								};

	// Print the solution
	floydWarshall(graph, V);
	return 0;
}

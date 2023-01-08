#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// undirected and directed both
template <typename T>
class Graph
{
	unordered_map<T, list<T>> adj;
	
public:
	void addEdge(T x, T y, bool bidir) // bidir = true mean directed 
	{
		adj[x].push_back(y);
		if (bidir)
		{
			adj[y].push_back(x);
		}
	}

	void printAdjList()
	{
		for (auto i : adj)
		{
			cout << i.first << " -> ";

			for (auto j : i.second)
			{
				cout << j << ", ";
			}
			cout << endl;
		}
	}
	
	void printAdjMatrix()
	{
		int n = adj.size();
		int** matrix = new int* [n];
		for (int i = 0; i < n; i++)
		{
			matrix[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = 0;
			}
		}

		for (auto p : adj)
		{
			int i = p.first;
			for (int j : p.second)
			{
				matrix[i][j] = 1;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};



int main()
{
	Graph<int> g;
	
	g.addEdge(0, 1, false);
	g.addEdge(0, 4, true);
	g.addEdge(4, 3, true);
	g.addEdge(1, 4, false);
	g.addEdge(1, 2, true);
	g.addEdge(2, 3, true);
	g.addEdge(1, 3, false);
	
	cout << endl << "Adjacency List: " << endl;

	g.printAdjList();

	cout << endl << "Adjacency Matrix: " << endl;
	g.printAdjMatrix();
	return 0;
}
	
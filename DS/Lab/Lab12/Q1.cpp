#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

// Prims Algorithm

class Graph
{
	int V;
	list<pair<int, int> >* adj;
	map<int, int> m;
	map<int, int>::iterator it;
	int* key;
	int* parent;
	bool* mstSet;
	int minKey();
	void printMST();
public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void primMST();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<pair<int, int> >[V];
	key = new int[V];
	parent = new int[V];
	mstSet = new bool[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

int Graph::minKey()
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

void Graph::printMST()
{
	cout << "Edge \tWeight \tParent" << endl;
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t" << key[i] << " \t" << parent[i] << endl;
}

void Graph::primMST()
{
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < V - 1; count++)
	{
		int u = minKey();
		mstSet[u] = true;
		list<pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;
			if (mstSet[v] == false && weight < key[v])
				parent[v] = u, key[v] = weight;
		}
	}
	printMST();
}

int main()
{
	int V, E, u, v, w;
	cin >> V >> E;
	Graph g(V);
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}
	g.primMST();
	return 0;
}

// Inputs

//5 7
//0 1 2
//0 3 6
//1 2 3
//1 3 8
//1 4 5
//2 4 7
//3 4 9




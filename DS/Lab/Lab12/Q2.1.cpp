// Kruskal Algorithm for Minimum Spanning Tree

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph {
private:
	int V;
	vector<vector<int>> edges;
	vector<vector<int>> mst;
	vector<int> parent;
	vector<int> rank;
	int find(int i);
	void Union(int x, int y);
	
public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void kruskal();
	void printMST();
};

Graph::Graph(int V) {
	this->V = V;
	parent.resize(V);
	rank.resize(V);
	for (int i = 0; i < V; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}

void Graph::addEdge(int u, int v, int w) {
	edges.push_back({ w, u, v });
}

int Graph::find(int i) {
	if (parent[i] != i)
		parent[i] = find(parent[i]);
	return parent[i];
}

void Graph::Union(int x, int y) {
	int xroot = find(x);
	int yroot = find(y);
	if (rank[xroot] < rank[yroot])
		parent[xroot] = yroot;
	else if (rank[xroot] > rank[yroot])
		parent[yroot] = xroot;
	else {
		parent[yroot] = xroot;
		rank[xroot]++;
	}
}

void Graph::kruskal() {
	int e = 0;
	int i = 0;
	while (e < V - 1) {
		int u = edges[i][1];
		int v = edges[i][2];
		int set_u = find(u);
		int set_v = find(v);
		if (set_u != set_v) {
			mst.push_back(edges[i]);
			Union(set_u, set_v);
			e++;
		}
		i++;
	}
}

void Graph::printMST() {
	int mst_wt = 0;
	cout << "Edge Weight" << endl;
	for (int i = 0; i < mst.size(); i++) {
		cout << mst[i][1] << " - " << mst[i][2] << " " << mst[i][0] << endl;
		mst_wt += mst[i][0];
	}
	cout << "Total weight of MST is " << mst_wt << endl;
}

int main() {
	int V = 9;
	Graph g(V);
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
	g.kruskal();
	g.printMST();
	return 0;
}
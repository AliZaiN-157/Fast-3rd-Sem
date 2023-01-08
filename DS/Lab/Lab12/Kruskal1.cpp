#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

// Kruskal's algorithm 

class Edge {
public:
	int u, v, w; // u and v are the vertices, w is the weight
	Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

class Graph {
public:
	int n;
	vector<Edge> edges;
	Graph(int n) : n(n) {}
	void addEdge(int u, int v, int w) {
		edges.push_back(Edge(u, v, w));
	}
};

class DisjointSet {
public:
	int n;
	vector<int> parent;
	DisjointSet(int n) : n(n) {
		parent.resize(n);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u])
			return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v)
			return;
		parent[u] = v;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}
	DisjointSet ds(n);
	sort(g.edges.begin(), g.edges.end(), [](Edge& e1, Edge& e2) {
		return e1.w < e2.w;
		});
	int totalWeight = 0;
	for (Edge& e : g.edges) {
		if (ds.find(e.u) != ds.find(e.v)) {
			ds.merge(e.u, e.v);
			totalWeight += e.w;
		}
	}
	cout << totalWeight << endl;
	return 0;
}

// inputs
// 6 9
// 0 1 1
// 0 2 2
// 0 3 3
// 1 2 4
// 1 4 5
// 2 3 6
// 2 4 7
// 2 5 8
// 3 5 9

// output
// 21


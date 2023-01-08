#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// kruskals algorithm

class Graph {
	int V;
	list<pair<int, int>>* adj;
	map<int, int> parent;
	map<int, int> rank;
public:
	Graph(int V) {
		this->V = V;
		adj = new list<pair<int, int>>[V];
	}
	void addEdge(int u, int v, int w) {
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	int find(int i) {
		if (parent[i] == -1)
			return i;
		return find(parent[i]);
	}
	void Union(int x, int y) {
		int xset = find(x);
		int yset = find(y);
		if (xset == yset)
			return;
		if (rank[xset] < rank[yset])
			parent[xset] = yset;
		else if (rank[xset] > rank[yset])
			parent[yset] = xset;
		else {
			parent[yset] = xset;
			rank[xset]++;
		}
	}
	void kruskalMST() {
		vector<pair<int, pair<int, int>>> edges;
		for (int i = 0; i < V; i++) {
			for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
				edges.push_back(make_pair(it->second, make_pair(i, it->first)));
			}
		}
		sort(edges.begin(), edges.end());
		for (int i = 0; i < V; i++) {
			parent[i] = -1;
			rank[i] = 0;
		}
		int i = 0;
		int e = 0;
		while (e < V - 1) {
			int x = find(edges[i].second.first);
			int y = find(edges[i].second.second);
			if (x != y) {
				cout << edges[i].second.first << " - " << edges[i].second.second << endl;
				Union(x, y);
				e++;
			}
			i++;
		}
	}
};

int main() {
	Graph g(4);
	g.addEdge(0, 1, 10);
	g.addEdge(0, 2, 6);
	g.addEdge(0, 3, 5);
	g.addEdge(1, 3, 15);
	g.addEdge(2, 3, 4);
	g.kruskalMST();
	return 0;
}

//Graph g(7);
//g.addEdge(1, 2, 28);
//g.addEdge(1, 6, 10);
//g.addEdge(2, 7, 14);
//g.addEdge(2, 3, 16);
//g.addEdge(3, 4, 12);
//g.addEdge(7, 4, 18);
//g.addEdge(7, 5, 24);
//g.addEdge(4, 5, 22);
//g.addEdge(6, 5, 25);
//g.kruskalMST();
#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

// BFS_DFS algorithm

class Graph {
	unordered_map<int, bool> visited_bfs;
	unordered_map<int, bool> visited_dfs;
	unordered_map<int, bool> visited_sort;
	unordered_map<int, list<int>> adjList;
	
public:
	Graph() {}
	void addEdge(int u, int v, bool bidir = true) {
		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
	}

	void printAdjList() {
		for (auto i : adjList) {
			cout << i.first << " -> ";
			for (auto entry : i.second) {
				cout << entry << ", ";
			}
			cout << endl;
		}
	}

	void BFS(int src) {
		queue<int> q; 
		q.push(src);
		visited_bfs[src] = true;  

		while (!q.empty()) {
			int node = q.front();
			cout << node << " ";
			q.pop();

			for (int neighbour : adjList[node]) {
				if (!visited_bfs[neighbour]) {
					q.push(neighbour);
					visited_bfs[neighbour] = true;
				}
			}
		}
	}

	void DFS(int node) {
		visited_dfs[node] = true;
		cout << node << " ";

		// try to find out a node which is neighbour of current node and not yet visited
		for (int neighbour : adjList[node]) {
			if (!visited_dfs[neighbour]) {
				DFS(neighbour);
			}
		}
	}
	
	// Sort the graph topologically using DFs
	void topologicalSort() {
		stack<int> s;
		for (auto i : adjList) {
			int node = i.first;
			if (!visited_sort[node]) {
				DFS_helper(node, s);
			}
		}

		// Print contents of stack
		while (!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}
	}
	
	void DFS_helper(int node, stack<int>& s) {
		visited_sort[node] = true;
		for (int neighbour : adjList[node]) {
			if (!visited_sort[neighbour]) {
				DFS_helper(neighbour, s);
			}
		}
		// At this point, all the children of current node have been visited
		s.push(node);
	}

	
};

int main() {
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(3, 4);

	g.printAdjList();

	cout << "BFS: ";
	g.BFS(0);
	cout << endl << "DFS: ";
	g.DFS(0);
	cout << endl << "Topological Sort: ";
	g.topologicalSort();

	return 0;
}
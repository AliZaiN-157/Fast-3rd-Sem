#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Create a Templet type of Graph class through doubly linked list which have
// above functionality
template <typename T>
class Graph {
	// Create a node class which will be used to create a node of graph
	class Node {
	public:
		T data;
		vector<Node*> neighbours;
		bool visited;
		Node(T data) {
			this->data = data;
			this->visited = false;
		}
	};

	// Create a vector of nodes which will be used to store the nodes of graph
	vector<Node*> nodes;

public:
	// Create a node of graph and add it to the vector of nodes
	void addNode(T data) {
		Node* node = new Node(data);
		nodes.push_back(node);
	}

	// Add an edge between two nodes of graph
	void addEdge(T data1, T data2) {
		Node* node1 = getNode(data1);
		Node* node2 = getNode(data2);
		node1->neighbours.push_back(node2);
		node2->neighbours.push_back(node1);
	}

	// Get the node of graph by its data
	Node* getNode(T data) {
		for (int i = 0; i < nodes.size(); i++) {
			if (nodes[i]->data == data) {
				return nodes[i];
			}
		}
		return NULL;
	}

	// Print the graph
	void printGraph() {
		for (int i = 0; i < nodes.size(); i++) {
			cout << nodes[i]->data << " : ";
			for (int j = 0; j < nodes[i]->neighbours.size(); j++) {
				cout << nodes[i]->neighbours[j]->data << " ";
			}
			cout << endl;
		}
	}

	// DFS traversal of graph
	void dfs(Node* node) {
		if (node == NULL) {
			return;
		}
		node->visited = true;
		cout << node->data << " ";
		for (int i = 0; i < node->neighbours.size(); i++) {
			if (!node->neighbours[i]->visited) {
				dfs(node->neighbours[i]);
			}
		}
	}

	// DFS traversal of graph
	void dfs(T data) {
		Node* node = getNode(data);
		dfs(node);
	}

	// BFS traversal of graph
	void bfs(Node* node) {
		if (node == NULL) {
			return;
		}
		queue<Node*> q;
		q.push(node);
		node->visited = true;
		while (!q.empty()) {
			Node* temp = q.front();
			q.pop();
			cout << temp->data << " ";
			for (int i = 0; i < temp->neighbours.size(); i++) {
				if (!temp->neighbours[i]->visited) {
					q.push(temp->neighbours[i]);
					temp->neighbours[i]->visited = true;
				}
			}
		}
	}
	
	// BFS traversal of graph
	void bfs(T data) {
		Node* node = getNode(data);
		bfs(node);
	}
};

int main() {
	Graph<int> g;
	g.addNode(1);
	g.addNode(2);
	g.addNode(3);
	g.addNode(4);
	g.addNode(5);
	g.addNode(6);
	g.addNode(7);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 6);
	g.addEdge(3, 7);
	g.printGraph();
	cout << "DFS : ";
	g.dfs(1);
	cout << endl;
	cout << "BFS : ";
	g.bfs(1);
	cout << endl;
	return 0;
}

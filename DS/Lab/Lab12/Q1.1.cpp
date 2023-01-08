#include <iostream>
#include <vector>

using namespace std;

// Prims Algorithm with char nodes

class Graph {
private:
	vector<vector<int>> adjMatrix;
	vector<char> nodes;
	int size;
public:
	Graph(int size) {
		this->size = size;
		adjMatrix.resize(size);
		for (int i = 0; i < size; i++) {
			adjMatrix[i].resize(size);
		}
	}

	void addEdge(char node1, char node2, int weight) {
		int index1 = findNode(node1);
		int index2 = findNode(node2);
		adjMatrix[index1][index2] = weight;
		adjMatrix[index2][index1] = weight;
	}

	void addNode(char node) {
		nodes.push_back(node);
	}

	int findNode(char node) {
		for (int i = 0; i < nodes.size(); i++) {
			if (nodes[i] == node) {
				return i;
			}
		}
		return -1;
	}

	void printMatrix() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	void printNodes() {
		for (int i = 0; i < nodes.size(); i++) {
			cout << nodes[i] << " ";
		}
		cout << endl;
	}

	void prims() {
		vector<int> key(size, INT_MAX);
		vector<int> parent(size, -1);
		vector<bool> inMST(size, false);
		key[0] = 0;
		for (int i = 0; i < size - 1; i++) {
			int min = INT_MAX;
			int minIndex;
			for (int j = 0; j < size; j++) {
				if (inMST[j] == false && key[j] < min) {
					min = key[j];
					minIndex = j;
				}
			}
			inMST[minIndex] = true;
			for (int j = 0; j < size; j++) {
				if (adjMatrix[minIndex][j] != 0 && inMST[j] == false && adjMatrix[minIndex][j] < key[j]) {
					parent[j] = minIndex;
					key[j] = adjMatrix[minIndex][j];
				}
			}
		}
		for (int i = 1; i < size; i++) {
			cout << nodes[parent[i]] << " - " << nodes[i] << endl;
		}

	}

};

int main() {
	Graph g(7);
	g.addNode('A');
	g.addNode('B');
	g.addNode('C');
	g.addNode('D');
	g.addNode('E');
	g.addNode('F');
	g.addNode('G');
	g.addEdge('A', 'B', 1);
	g.addEdge('A', 'C', 5);
	g.addEdge('B', 'C', 4);
	g.addEdge('B', 'D', 8);
	g.addEdge('B', 'E', 7);
	g.addEdge('C', 'F', 2);
	g.addEdge('C', 'D', 6);
	g.addEdge('D', 'E', 11);
	g.addEdge('D', 'F', 9);
	g.addEdge('E', 'F', 3);
	g.addEdge('E', 'G', 10);
	g.addEdge('F', 'G', 12);
	g.prims();

	
}
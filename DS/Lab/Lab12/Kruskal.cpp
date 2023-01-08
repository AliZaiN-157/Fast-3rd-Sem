#include<iostream>

using namespace std;

// Kruskal's algorithm to find Minimum Spanning Tree of a given connected, undirected and weighted graph

class Edge
{
public:
	int source, destination, weight;
};

class Graph
{
public:
	int V, E;
	Edge* edge;
};

Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

class subset
{
public:
	int parent;
	int rank;
};

int find(subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int myComp(const void* a, const void* b)
{
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;
	return a1->weight > b1->weight;
}

void KruskalMST(Graph* graph)
{
	int V = graph->V;
	Edge result[V];
	int e = 0;
	int i = 0;
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
	subset* subsets = new subset[(V * sizeof(subset))];
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	while (e < V - 1 && i < graph->E)
	{
		Edge next_edge = graph->edge[i++];
		int x = find(subsets, next_edge.source);
		int y = find(subsets, next_edge.destination);
		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
	}
	cout << "Following are the edges in the constructed MST " << endl;
	for (i = 0; i < e; ++i)
		cout << result[i].source << " -- " << result[i].destination << " == " << result[i].weight << endl;
	return;
}

int main()
{
	int V = 6;
	int E = 9;
	Graph* graph = createGraph(V, E);
	graph->edge[0].source = 0;
	graph->edge[0].destination = 1;
	graph->edge[0].weight = 1;
	graph->edge[1].source = 0;
	graph->edge[1].destination = 2;
	graph->edge[1].weight = 2;
	graph->edge[2].source = 0;
	graph->edge[2].destination = 3;
	graph->edge[2].weight = 3;
	graph->edge[3].source = 1;
	graph->edge[3].destination = 2;
	graph->edge[3].weight = 4;
	graph->edge[4].source = 1;
	graph->edge[4].destination = 4;
	graph->edge[4].weight = 5;
	graph->edge[5].source = 2;
	graph->edge[5].destination = 3;
	graph->edge[5].weight = 6;
	graph->edge[6].source = 2;
	graph->edge[6].destination = 4;
	graph->edge[6].weight = 7;
	graph->edge[7].source = 2;
	graph->edge[7].destination = 5;
	graph->edge[7].weight = 8;
	graph->edge[8].source = 3;
	graph->edge[8].destination = 5;
	graph->edge[8].weight = 9;
	KruskalMST(graph);
	return 0;
}
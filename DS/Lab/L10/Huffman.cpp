#include <iostream>
#include <queue>

using namespace std;


// A Huffman tree node
class Node {
public:
	char ch; // non-leaf node: ch is 0
	int freq; // frequency of character
	Node* left, * right; // left and right child

	Node(char ch, int freq, Node* left, Node* right) {
		this->ch = ch;
		this->freq = freq;
		this->left = left;
		this->right = right;
	}
};

// For comparison of two heap nodes (needed in min heap)
class comp {
public:
	bool operator()(const Node* l, const Node* r) {
		return l->freq > r->freq;
	}
};

// Prints huffman codes from the root of Huffman Tree.
void printCodes(Node* root, string str) {
	if (!root)
		return;

	if (root->ch != '$')
		cout << root->ch << ": " << str << " ";
	
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size) {
	Node* left, * right, * top;

	// Create a min heap & inserts all characters of data[]
	priority_queue<Node*, vector<Node*>, comp> minHeap;
	for (int i = 0; i < size; ++i)
		minHeap.push(new Node(data[i], freq[i], NULL, NULL));

	// Iterate while size of heap doesn't become 1
	while (minHeap.size() != 1) {
		// Extract the two minimum freq items from min heap
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		// Create a new internal node with frequency equal to the sum of the two nodes frequencies. Make the two extracted node as left and right children of this new node. Add this node to the min heap
		top = new Node('$', left->freq + right->freq, left, right);
		minHeap.push(top);
	}

	// Print Huffman codes using the Huffman tree built above
	printCodes(minHeap.top(), "");
}

// Driver program to test above functions

int main() {
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	HuffmanCodes(arr, freq, size);

	return 0;
}

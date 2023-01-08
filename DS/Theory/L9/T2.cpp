#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node() {
		data = 0;
		left = NULL;
		right = NULL;
	}

	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class BST {
public:
	Node* addnode(int data) {
		Node* newnode = new Node(data);
		return newnode;
	}

	Node* insert(Node* root, int data) {
		if (root == NULL) {
			root = addnode(data);
		}
		else if (data <= root->data) {
			root->left = insert(root->left, data);
		}
		else {
			root->right = insert(root->right, data);
		}
		return root;
	}

	void inorder(Node* root) {
		if (root == NULL) {
			return;
		}
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	void preorder(Node* root) {
		if (root == NULL) {
			return;
		}
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}

	// preorder iterative function
	void preorder_iterative(Node* root) {
		if (root == NULL) {
			return;
		}
		stack<Node*> s; // Creating a Stack of type Node
		s.push(root); // Pushing the root node into the stack
		while (!s.empty()) { // While the stack is not empty
			Node* temp = s.top(); // Creating a temporary node and assigning it the top of the stack (root)
			cout << temp->data << " "; // Printing the data of the root node
			s.pop(); 
			if (temp->right != NULL) { // If the right child of the root node is not NULL
				s.push(temp->right); // Push the right child of the root node into the stack
			}
			if (temp->left != NULL) { // If the left child of the root node is not NULL
				s.push(temp->left); // Push the left child of the root node into the stack
			}
		} 
	}
};

int main() {

	BST tree;
	Node* root = NULL;
	
	int arr[] = { 15, 10, 20, 8, 12, 16, 25 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
	for (int i = 0; i < size; i++) {
		root = tree.insert(root, arr[i]);
	}

	cout << "Inorder: ";
	tree.inorder(root);
	
	cout << endl << "Preorder: ";
	tree.preorder(root);

	cout << endl << "Preorder Iterative: ";
	tree.preorder_iterative(root);
}
#include <iostream>

using namespace std;

// Find a pair with given sum in a Balanced BST

class Node {
public:
	int data;
	Node* left;
	Node* right;
	
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class AVL {
public:
	Node* root;

	AVL() {
		root = NULL;
	}

	Node* insert(Node* root, int data) {
		if (root == NULL) {
			root = new Node(data);
			return root;
		}

		if (data < root->data) {
			root->left = insert(root->left, data);
		}
		else {
			root->right = insert(root->right, data);
		}

		int balance = getBalance(root);

		// Left Left Case
		if (balance > 1 && data < root->left->data) {
			return rightRotate(root);
		}

		// Right Right Case
		if (balance < -1 && data > root->right->data) {
			return leftRotate(root);
		}

		// Left Right Case
		if (balance > 1 && data > root->left->data) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		// Right Left Case
		if (balance < -1 && data < root->right->data) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	Node* rightRotate(Node* y) {
		Node* x = y->left;
		Node* T2 = x->right;

		// Perform rotation
		x->right = y;
		y->left = T2;

		return x;
	}

	Node* leftRotate(Node* x) {
		Node* y = x->right;
		Node* T2 = y->left;

		// Perform rotation
		y->left = x;
		x->right = T2;

		return y;
	}

	int getBalance(Node* root) {
		if (root == NULL) {
			return 0;
		}

		return height(root->left) - height(root->right);
	}

	int height(Node* root) {
		if (root == NULL) {
			return 0;
		}

		return 1 + max(height(root->left), height(root->right));
	}

	void inorder(Node* root) {
		if (root == NULL) {
			return;
		}

		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	// Find a pair with given sum in a Balanced BST
};

int main() {
	AVL tree;

	tree.root = tree.insert(tree.root, 10);
	tree.root = tree.insert(tree.root, 20);
	tree.root = tree.insert(tree.root, 30);
	tree.root = tree.insert(tree.root, 40);
	tree.root = tree.insert(tree.root, 50);
	tree.root = tree.insert(tree.root, 25);

	tree.inorder(tree.root);

	return 0;
}

	

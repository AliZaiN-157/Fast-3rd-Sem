#include <iostream>

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
	
	// AutoGrader function
	int autoGrader(Node* root) {
		if (root == NULL) {
			return 1;
		}
		if (root->left != NULL && root->left->data > root->data) {
			return 0;
		}
		if (root->right != NULL && root->right->data < root->data) {
			return 0;
		}
		if (autoGrader(root->left) == 0 || autoGrader(root->right) == 0) {
			return 0;
		}
		return 10;
	}

	// Display function
	void display(Node* root) {
		if (root == NULL) {
			return;
		}
		display(root->left);
		cout << root->data << " ";
		display(root->right);
	}

};


int main() {
	BST b;
	Node* root = NULL;

	cout << "Tree 1: ";
	root = b.addnode(10);
	root->left = b.addnode(9);
	root->right = b.addnode(15);
	root->left->left = b.addnode(10);
	root->left->right = b.addnode(8);
	root->right->left = b.addnode(12);
	root->right->right = b.addnode(2); 
	b.display(root);
	cout << "\nMarks: " << endl;
	cout << b.autoGrader(root) << endl;

	BST b1;
	Node* root1 = NULL;
	
	cout << "Tree 2: ";
	root1 = b1.addnode(40);
	root1->left = b1.addnode(30);
	root1->right = b1.addnode(50);
	root1->left->left = b1.addnode(20);
	root1->left->right = b1.addnode(35);
	root1->right->left = b1.addnode(45);
	root1->right->right = b1.addnode(60);
	
	b.display(root1);
	cout << "\nMarks: " << endl;
	cout << b1.autoGrader(root1) << endl;
}
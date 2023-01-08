#include <iostream>

using namespace std;

// Find commont Parent

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

Node* findCommonParent(Node* root, int n1, int n2) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == n1 || root->data == n2) {
		return root;
	}
	Node* left = findCommonParent(root->left, n1, n2);
	Node* right = findCommonParent(root->right, n1, n2);
	if (left != NULL && right != NULL) {
		return root;
	}
	if (left != NULL) {
		return left;
	}
	if (right != NULL) {
		return right;
	}
	return NULL;
}

int main() {
	Node* root = new Node(50);
	root->left = new Node(17);
	root->right = new Node(72);
	root->left->left = new Node(12);
	root->left->right = new Node(23);
	root->right->left = new Node(54);
	root->right->right = new Node(76);
	root->left->left->left = new Node(9);
	root->left->left->right = new Node(14);
	root->left->right->left = new Node(19);
	root->right->left->right = new Node(67);
	
	Node* commonParent = findCommonParent(root, 54, 76);
	cout << commonParent->data << endl;

	Node* commonParent1 = findCommonParent(root, 23, 54);
	cout << commonParent1->data << endl;

	Node* commonParent2 = findCommonParent(root, 14, 23);
	cout << commonParent2->data << endl;
}
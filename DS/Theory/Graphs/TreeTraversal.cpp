#include <iostream>
#include <queue>
#include <stack>

using namespace std;

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

void printLevelOrder(Node* root) {
	if (root == NULL) return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* node = q.front();
		cout << node->data << " ";
		q.pop();
		if (node->left != NULL) q.push(node->left);
		if (node->right != NULL) q.push(node->right);
	}
}

void printPreOrder(Node* root) {
	if (root == NULL) return;
	stack<Node*> s;
	s.push(root);
	while (!s.empty()) {
		Node* node = s.top();
		cout << node->data << " ";
		s.pop();
		if (node->right != NULL) s.push(node->right);
		if (node->left != NULL) s.push(node->left);
	}
}

void printPostOrder(Node* root) {
	if (root == NULL) return;
	stack<Node*> s;
	s.push(root);
	stack<int> out;
	while (!s.empty()) {
		Node* node = s.top();
		out.push(node->data);
		s.pop();
		if (node->left != NULL) s.push(node->left);
		if (node->right != NULL) s.push(node->right);
	}
	while (!out.empty()) {
		cout << out.top() << " ";
		out.pop();
	}
}

// inorder
void printInOrder(Node* root) {
	if (root == NULL) return;
	stack<Node*> s;
	Node* curr = root;
	while (curr != NULL || !s.empty()) {
		while (curr != NULL) {
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		cout << curr->data << " ";
		curr = curr->right;
	}
}

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	cout << "Level Order: ";
	printLevelOrder(root);
	cout << endl;
	cout << "Pre Order: ";
	printPreOrder(root);
	cout << endl;
	cout << "Post Order: ";
	printPostOrder(root);
	cout << endl;
	cout << "In Order: ";
	printInOrder(root);
	cout << endl;
	return 0;
}


#include <iostream>
using namespace std;

class Node {
public:
	Node* left, * right;
	char ch;
	Node() {
		left = right = NULL;
	}
	
	Node(char c) {
		left = right = NULL;
		ch = c;
	}
};

Node* decode(Node* root, string s) {
	Node* p = root;
	for (int i = 0; i < s.length(); i++) {

		if (s[i] == '0') {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	return p;
}

int main() {
	
	Node* root = new Node();
	root->left = new Node();
	root->right = new Node();
	root->left->left = new Node();
	root->left->left->left = new Node('E');
	root->left->left->right = new Node('A');
	root->left->right = new Node('D');
	root->right->left = new Node('B');
	root->right->right = new Node('C');
	
	string s;
	cin >> s;
	Node* p = decode(root, s);
	cout << p->ch << endl;
	return 0;
}

// Inputs from Task 1:
// Inputs -> Output
// 001 -> A
// 10 -> B
// 11 -> C
// 01 -> D
// 000 -> E



			



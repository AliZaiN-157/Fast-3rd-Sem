#include <iostream>

using namespace std;

// Given a BST and a range of keys(values), remove nodes from BST that have keys outside the given range

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

class BST
{
public:
	Node* addNode(int data)
	{
		Node* newNode = new Node(data);
		return newNode;
	}

	Node* insert(Node* root, int data)
	{
		if (root == NULL)
		{
			root = addNode(data);
		}
		else if (data <= root->data)
		{
			root->left = insert(root->left, data);
		}
		else
		{
			root->right = insert(root->right, data);
		}
		return root;
	}

	void inorder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	Node* removeOutsideRange(Node* root, int min, int max)
	{
		if (root == NULL)
		{
			return NULL;
		}
		root->left = removeOutsideRange(root->left, min, max);
		root->right = removeOutsideRange(root->right, min, max);

		if (root->data < min)
		{
			Node* rChild = root->right;
			delete root;
			return rChild;
		}
		if (root->data > max)
		{
			Node* lChild = root->left;
			delete root;
			return lChild;
		}
		return root;
	}

	
	
};

int main() {
	
	BST b;
	
	Node* root = NULL;
	
	root = b.insert(root, 15);
	root = b.insert(root, 10);
	root = b.insert(root, 20);
	root = b.insert(root, 8);
	root = b.insert(root, 12);
	root = b.insert(root, 16);
	root = b.insert(root, 25);
	
	b.inorder(root);
	
	cout << endl << "Remove: ";

	root = b.removeOutsideRange(root, 9, 12);
	
	b.inorder(root);

	return 0;
}
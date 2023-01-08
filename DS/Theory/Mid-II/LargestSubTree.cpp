#include <iostream>

using namespace std;

// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.

class Node {
public:
	int data;
	Node* left, * right;
	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

class BST
{
public:
	Node* addNode(int d)
	{
		Node* newNode = new Node(d);
		return newNode;
	}

	Node* InsertBST(Node* root, int d)
	{
		if (root == NULL)
		{
			root = addNode(d);
			return root;
		}
		else if (d <= root->data)
		{
			root->left = InsertBST(root->left, d);
		}
		else
		{
			root->right = InsertBST(root->right, d);
		}
		return root;
	}

	void Inorder(Node* root)
	{
		if (root == NULL)
			return;
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}

	// largest sub tree
	int LargestSubTree(Node* root, int max)
	{
		if (root == NULL)
			return 0;

		int left = LargestSubTree(root->left, max);
		int right = LargestSubTree(root->right, max);

		if (left == -1 || right == -1)
			return -1;

		if (root->left != NULL && root->data < root->left->data)
			return -1;

		if (root->right != NULL && root->data > root->right->data)
			return -1;

		int size = left + right + 1;
		if (size > max)
			max = size;

		return size;
	}

};



int main()
{
	BST bst;
	Node* root = NULL;
	root = bst.InsertBST(root, 40);
	root = bst.InsertBST(root, 32);
	root = bst.InsertBST(root, 65);
	root = bst.InsertBST(root, 15);
	root = bst.InsertBST(root, 90);
	root = bst.InsertBST(root, 29);
	root = bst.InsertBST(root, 43);
	root = bst.InsertBST(root, 88);
	root = bst.InsertBST(root, 11);
	bst.Inorder(root);
	cout << endl;
	cout << bst.LargestSubTree(root, 0);
	return 0;
}
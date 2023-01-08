#include <iostream>

using namespace std;

// Size and Height of a Binary Search Tree

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

class BST {
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
	
	int height(Node* root)
	{
		if (root == NULL)
		{
			return -1;
		}
		else
		{
			return max(height(root->left), height(root->right)) + 1;
		}
	}
	
	int size(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		else
		{
			return size(root->left) + size(root->right) + 1;
		}
	}

	void display(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			display(root->left);
			cout << root->data << " ";
			display(root->right);
		}
	}

	// Given the root of a binary tree, determine if it is a valid binary search tree(BST).
	
	bool isValidBST(Node* root, Node* min, Node* max)
	{
		if (root == NULL)
		{
			return true;
		}
		else if (min != NULL && root->data <= min->data)
		{
			return false;
		}
		else if (max != NULL && root->data >= max->data)
		{
			return false;
		}
		else
		{
			return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
		}
	}

};

int main()
{
	BST objbst;
	Node* root = NULL;
	root = objbst.InsertBST(root, 45);
	root = objbst.InsertBST(root, 32);
	root = objbst.InsertBST(root, 60);
	root = objbst.InsertBST(root, 23);
	root = objbst.InsertBST(root, 54);
	root = objbst.InsertBST(root, 78);
	objbst.display(root);
	
	cout << "\nHeight of BST: " << objbst.height(root) << endl;
	cout << "Size of BST: " << objbst.size(root) << endl;

	if (objbst.isValidBST(root, NULL, NULL))
	{
		cout << "Valid BST" << endl;
	}
	else
	{
		cout << "Invalid BST" << endl;
	}

	return 0;
}
		
#include <iostream>

using namespace std;

// max and min depth of a binary tree

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
	
};

int maxDepth(Node* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int lDepth = maxDepth(root->left);
		int rDepth = maxDepth(root->right);

		if (lDepth > rDepth)
			return lDepth + 1;
		else
			return rDepth + 1;
	}
}

int minDepth(Node* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int lDepth = minDepth(root->left);
		int rDepth = minDepth(root->right);

		if (lDepth < rDepth)
			return lDepth + 1;
		else
			return rDepth + 1;
	}
}

// print nodes at a given level
void printGivenLevel(Node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

// level order traversal of its nodes values
void printLevelOrder(Node* root)
{
	int h = maxDepth(root);
	int i;
	for (i = 1; i <= h; i++) {
		cout << "[";
		printGivenLevel(root, i);
		cout << "],";
	}
}


int main()
{
	Node* root = new Node(3);
	root->left = new Node(9);
	root->right = new Node(20);
	root->right->left = new Node(15);
	root->right->right = new Node(7);

	cout << "Max Depth: " << maxDepth(root) << endl;
	cout << "Min Depth: " << minDepth(root) << endl;

	cout << "Level Order Traversal: ";
	printLevelOrder(root);
	

	return 0;
}
#include <iostream>

using namespace std;

// Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	int height;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
		height = 1;
	}
};

class AVL
{
public:

	Node* insert(Node* root, int data)
	{
		if (root == NULL)
		{
			root = new Node(data);
			return root;
		}

		if (data < root->data)
		{
			root->left = insert(root->left, data);
		}
		else if (data > root->data)
		{
			root->right = insert(root->right, data);
		}
		else
		{
			return root;
		}

		int balance = getBalance(root);

		// Left Left Case
		if (balance > 1 && data < root->left->data)
		{
			return rightRotate(root);
		}

		// Right Right Case
		if (balance < -1 && data > root->right->data)
		{
			return leftRotate(root);
		}

		// Left Right Case
		if (balance > 1 && data > root->left->data)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		// Right Left Case
		if (balance < -1 && data < root->right->data)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	Node* rightRotate(Node* y)
	{
		Node* x = y->left;
		Node* T2 = x->right;

		// Perform rotation
		x->right = y;
		y->left = T2;

		// Return new root
		return x;
	}

	Node* leftRotate(Node* x)
	{
		Node* y = x->right;
		Node* T2 = y->left;

		// Perform rotation
		y->left = x;
		x->right = T2;

		// Return new root
		return y;
	}

	// height
	int height(Node* N)
	{
		if (N == NULL)
			return 0;
		return N->height;
	}

	int getBalance(Node* N)
	{
		if (N == NULL)
		{
			return 0;
		}

		return height(N->left) - height(N->right);
	}

	Node* addNode(Node* root, int data)
	{
		if (root == NULL)
		{
			root = new Node(data);
			return root;
		}

		if (data < root->data)
		{
			root->left = addNode(root->left, data);
		}
		else
		{
			root->right = addNode(root->right, data);
		}

		return root;
	}

	Node* createAVL(int arr[], int start, int end)
	{
		if (start > end)
		{
			return NULL;
		}

		int mid = (start + end) / 2;
		Node* root = new Node(arr[mid]);
		root->left = createAVL(arr, start, mid - 1);
		root->right = createAVL(arr, mid + 1, end);

		return root;
	}

	void printInorder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}

		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}

	// display avl tree
	void display(Node* root, int space)
	{
		if (root == NULL)
		{
			return;
		}

		space += 10;

		display(root->right, space);

		cout << endl;
		for (int i = 10; i < space; i++)
		{
			cout << " ";
		}
		cout << root->data << endl;

		display(root->left, space);
	}
};

int main()
{
	AVL avl;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Node* root = avl.createAVL(arr, 0, n - 1);
	avl.printInorder(root);
	cout << endl;

	avl.display(root, 1);

	return 0;
}
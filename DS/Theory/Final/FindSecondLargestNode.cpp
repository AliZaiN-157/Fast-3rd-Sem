#include <iostream>

using namespace std;

// find second largest node 

class node {
public:
	int data;
	node* left, * right;
};

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return (Node);
}

node* findSecondLargest(node* root)
{
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return NULL;

	node* current = root;

	while (current != NULL)
	{
		if (current->left != NULL && current->right == NULL)
			return current->left;

		if (current->right != NULL && current->right->left == NULL && current->right->right == NULL)
			return current;

		current = current->right;
	}
	return NULL;
}

int main()
{
	node* root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	node* secondLargest = findSecondLargest(root);
	if (secondLargest != NULL)
		cout << "Second largest node is " << secondLargest->data << endl;
	else
		cout << "There is no second largest node" << endl;
	
	return 0;
}



#include <iostream>

using namespace std;

// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.


// Definition for a binary tree node.
class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node() : val(0), left(NULL), right(NULL) {}
	Node(int x) : val(x), left(NULL), right(NULL) {}
	Node(int x, Node* left, Node* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	void recoverTree(Node* root) {
		Node* first = NULL;
		Node* second = NULL;
		Node* prev = NULL;
		Node* curr = root;
		while (curr != NULL) {
			if (curr->left == NULL) {
				if (prev != NULL && prev->val > curr->val) {
					if (first == NULL) {
						first = prev;
					}
					second = curr;
				}
				prev = curr;
				curr = curr->right;
			}
			else {
				Node* temp = curr->left;
				while (temp->right != NULL && temp->right != curr) {
					temp = temp->right;
				}
				if (temp->right == NULL) {
					temp->right = curr;
					curr = curr->left;
				}
				else {
					temp->right = NULL;
					if (prev != NULL && prev->val > curr->val) {
						if (first == NULL) {
							first = prev;
						}
						second = curr;
					}
					prev = curr;
					curr = curr->right;
				}
			}
		}
		int temp = first->val;
		first->val = second->val;
		second->val = temp;
	}
};

int main()
{
	Node* root = new Node(1);
	root->left = new Node(3);
	root->left->right = new Node(2);
	Solution s;
	s.recoverTree(root);
	return 0;
}
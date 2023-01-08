#include <iostream>

using namespace std;

// You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

//Create a root node whose value is the maximum value in nums.
//Recursively build the left subtree on the subarray prefix to the left of the maximum value.
//Recursively build the right subtree on the subarray suffix to the right of the maximum value.
//Return the maximum binary tree built from nums.

// Example 1:

// Input: nums = [3,2,1,6,0,5]
// Output: [6,3,5,null,2,0,null,null,1]

// Example 2:

// Input: nums = [3,2,1]
// Output: [3,null,2,null,1]

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 1000
// All integers in nums are unique.

// Definition for a binary tree node.

class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

class BST
{
public:
	TreeNode* ConstructBST(int* arr, int start, int end) {
		if (start > end) {
			return NULL;
		}
		int max = arr[start];
		int maxIndex = start;
		for (int i = start + 1; i <= end; i++) {
			if (arr[i] > max) {
				max = arr[i];
				maxIndex = i;
			}
		}
		TreeNode* root = new TreeNode(max);
		root->left = ConstructBST(arr, start, maxIndex - 1);
		root->right = ConstructBST(arr, maxIndex + 1, end);
		return root;
	}
	void printInorder(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}
	
	void printPreorder(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		cout << root->data << " ";
		printPreorder(root->left);
		printPreorder(root->right);
	}
};

int main()
{
	int arr[] = { 3,2,1,6,0,5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BST bst;
	TreeNode* root = bst.ConstructBST(arr, 0, size - 1);
	bst.printPreorder(root);
	return 0;
}
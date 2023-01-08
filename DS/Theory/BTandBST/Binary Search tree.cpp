//Binary Search Tree

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int d){
			this->data = d;
			this->left = NULL;
			this->right = NULL;
		}
};



		
	Node* Insert_BST(Node* root,int d){
		if(root == NULL){
			root = new Node(d);
		}
		else if(root->data>d){
			root->left = Insert_BST(root->left,d);
		}
		else if(root->data<d){
			root->right = Insert_BST(root->right,d);
		}
		return root;
	}
	
	void Display(Node* root){
		if(root==NULL){
			return;
		}
		if(root!=NULL){
			Display(root->left);
			cout << root->data<<endl;
			Display(root->right);
		}
	}


int main(){
	Node* N1 = new Node(10);
	Insert_BST(N1,7);
	Insert_BST(N1,25);
	Insert_BST(N1,8);
	Insert_BST(N1,21);
	Insert_BST(N1,5);
	
	Display(N1);
	
}

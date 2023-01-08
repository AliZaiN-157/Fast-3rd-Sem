#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
public:
    Node* addNode(int data) {
        Node* newNode = new Node(data);
        return newNode;
    }

    int HeightBST(Node* root) {
        int h = -1;
        if (root != NULL) {
            int lst = HeightBST(root->left);
            int rst = HeightBST(root->right);
            int maxheight = max(lst, rst);
            h = maxheight + 1;
        }

        return h;
    }

    int BalanceFactor(Node* root) {
        if (root == NULL)
            return 0;

        else {
            int bf = HeightBST(root->left) - HeightBST(root->right);
            return bf;
        }
    }

    Node* rightRotate(Node* root) {
        Node* x = root->left;
        Node* temp = x->right;

        // Perform rotation  
        x->right = root;
        root->left = temp;

        return x;
    }

    Node* leftRotate(Node* root) {
        Node* y = root->right;
        Node* temp = y->left;

        // Perform rotation  
        y->left = root;
        root->right = temp;

        return y;
    }

    Node* insert(Node* root, int data) {
        if (root == NULL)
            return addNode(data);

        else if (data < root->data)
            root->left = insert(root->left, data);
        else if (data > root->data)
            root->right = insert(root->right, data);

        int bf = BalanceFactor(root);

        //LL
        if (bf < -1 && data > root->right->data)
            return leftRotate(root);
        //RR
        else if (bf > 1 && data < root->left->data)
            return rightRotate(root);
        //RL
        else if (bf < -1 && data < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        else if (bf > 1 && data > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        return root;
    }

	// delete Node
	Node* deleteNode(Node* root, int data) {
		if (root == NULL)
			return root;

		else if (data < root->data)
			root->left = deleteNode(root->left, data);
		else if (data > root->data)
			root->right = deleteNode(root->right, data);

		else {
			if (root->left == NULL && root->right == NULL) {
				delete root;
				root = NULL;
			}

			else if (root->left == NULL) {
				Node* temp = root;
				root = root->right;
				delete temp;
			}

			else if (root->right == NULL) {
				Node* temp = root;
				root = root->left;
				delete temp;
			}

			else {
				Node* temp = root->right;
				while (temp->left != NULL)
					temp = temp->left;

				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
		}

		if (root == NULL)
			return root;

		int bf = BalanceFactor(root);

		//LL
		if (bf < -1 && BalanceFactor(root->right) <= 0)
			return leftRotate(root);
		//RR
		else if (bf > 1 && BalanceFactor(root->left) >= 0)
			return rightRotate(root);
		//RL
		else if (bf < -1 && BalanceFactor(root->right) > 0) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		else if (bf > 1 && BalanceFactor(root->left) < 0) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		return root;
	}

	void preOrder(Node* root) {
		if (root != NULL) {
			cout << root->data << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	// display AVL Tree
	void display(Node* root, int space) {
		if (root == NULL)
			return;

		space += 10;

		display(root->right, space);

		cout << endl;
		for (int i = 10; i < space; i++)
			cout << " ";
		cout << root->data << endl;

		display(root->left, space);
	}
	
};

int main() {
    Node* root = NULL;
    BST objbst;

    root = objbst.insert(root, 54);
    root = objbst.insert(root, 11);
    root = objbst.insert(root, 87);
    root = objbst.insert(root, 23);
    root = objbst.insert(root, 111);
    root = objbst.insert(root, 120);
	
    cout << endl;
	
	cout << "AVL tree is: " << endl;
    objbst.display(root, 0);

    //cout << objbst.HeightBST(root);

    //                 54
    //         11              111
    // 23                  87        120
    //                                     
    //                                           
    //                              
}
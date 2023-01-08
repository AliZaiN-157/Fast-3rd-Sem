// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
public:
    Node* addNode(int data){
            Node* newNode = new Node(data);
            return newNode;
    }
    
    int heightBST(Node* root){
      int h = -1;
      if(root != NULL)
      {
        int lHeight = heightBST(root->left);
        int rHeight = heightBST(root->right);
        int maxHeight = max(lHeight,rHeight);
        h = maxHeight + 1;
      }
        return h;
    }
    
    int getBF(Node* root){
        if(root == NULL)
            return 0;
            
        return heightBST(root->left) - heightBST(root->right);
    }
    
    Node* rightRotate(Node *y) {
    Node *x = y -> left;
    Node *T2 = x -> right;

    // Perform rotation  
    x -> right = y;
    y -> left = T2;

    return x;
  }

    Node* leftRotate(Node *x) {
    Node *y = x -> right;
    Node *T2 = y -> left;

    // Perform rotation  
    y -> left = x;
    x -> right = T2;

    return y;
  }
    
    Node* InsertBST(Node* root, int data){
        if(root == NULL)
            return addNode(data);
            
        else if(data < root->data)
            root->left = InsertBST(root->left, data);
            
        else if(data > root->data)
            root->right = InsertBST(root->right, data);

        int bf = getBF(root);
        // Left Left Case  
        if (bf > 1 && data < root -> left -> data)
          return rightRotate(root);
    
        // Right Right Case  
        if (bf < -1 && data > root -> right -> data)
          return leftRotate(root);
    
        // Left Right Case  
        if (bf > 1 && data > root -> left -> data) {
          root -> left = leftRotate(root -> left);
          return rightRotate(root);
        }
    
        // Right Left Case  
        if (bf < -1 && data < root -> right -> data) {
          root -> right = rightRotate(root -> right);
          return leftRotate(root);
        }
 
        return root;
    
      }
    
    void Inorder(Node* root){
        if(root == NULL)
            return;
            
        Inorder(root->left);
        cout << root->data << "\t";
        Inorder(root->right);
    }
};

int main(){
    Node* root = NULL;
    BST objbst;
    
    root = objbst.InsertBST(root, 45);
    root = objbst.InsertBST(root, 32);
    root = objbst.InsertBST(root, 60);
    root = objbst.InsertBST(root, 23);
    root = objbst.InsertBST(root, 54);
    root = objbst.InsertBST(root, 78);
    root = objbst.InsertBST(root, 178);
    root = objbst.InsertBST(root, 179);
//                    45
//               32      60
//            23       54    78
//                               178
//                                    179

                                    
            
    objbst.Inorder(root);
    cout << endl << endl;
    
    cout << objbst.heightBST(root);
  
  }



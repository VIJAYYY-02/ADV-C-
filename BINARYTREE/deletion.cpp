#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Find inorder successor
Node* findSuccessor(Node* root) {
    Node* temp = root->right;

    while (temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

// Delete node from BST
Node* deleteNode(Node* root, int key) {

    if (root == NULL) {
        return NULL;
    }

    // Search in left subtree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }

    // Search in right subtree
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }

    // Node found
    else {

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: Only left child
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 4: Two children
        else {
            Node* temp = findSuccessor(root);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    // Example BST
    Node* root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(2);
    root->left->right = new Node(8);

    root->right->left = new Node(12);
    root->right->right = new Node(25);
     
    root->left->left->right= new Node(4);
    root->left->right->left= new Node(7);

    root->right->left->left=new Node(11);
    root->right->left->right=new Node(14);


    root->right->right->left=new Node(20);
    root->right->right->right=new Node(30);

    root->right->right->left->left=new Node(18);

    //delete 30 inorder
    //delete 2 inorder
    //delte 15 inorder


    cout << "Before deletion: ";
    inorder(root);
    int del;
    cout<<endl<<"node to delete :";
    cin>>del;
    
    root = deleteNode(root, del);
    
    cout << "\nAfter deletion: ";
    inorder(root); 
    cout<<endl<<"deleted node :"<<del;

    return 0;
}

//98,95,96 450
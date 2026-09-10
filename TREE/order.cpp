#include <iostream>
using namespace std;

struct node {
    char val;  // changed to char
    node* left;
    node* right;
    node(char data) {
        val = data;
        left = right = NULL;
    }
};

// Inorder Traversal (Left → Root → Right)
void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Preorder Traversal (Root → Left → Right)
void preorder(node* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left → Right → Root)
void postorder(node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    node* root = new node('A');
    root->left = new node('B');
    root->right = new node('C');
    root->left->left = new node('D');
    root->left->right = new node('E');
    root->right->right = new node('F');

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}

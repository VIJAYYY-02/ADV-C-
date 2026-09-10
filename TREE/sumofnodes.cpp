#include <iostream>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node(int data) {
        val = data;
        left = right = NULL;
    }
};

int sumNodes(node* root) {
    if (root == NULL)
        return 0;
    return root->val + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    node* root = new node(1);
    root->left = new node(1);
    root->right = new node(2);
    root->left->left = new node(2);
    root->left->right = new node(2);
    root->right->right = new node(1);

    cout << "Sum of node values: " << sumNodes(root);
}

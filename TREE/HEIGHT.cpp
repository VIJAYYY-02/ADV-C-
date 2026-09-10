#include <iostream>
using namespace std;

struct node {
    char val;  // using char for letters
    node* left;
    node* right;
    node(char data) {
        val = data;
        left = right = NULL;
    }
};

// Height of the tree
int height(node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int main() {
    node* root = new node('A');
    root->left = new node('B');
    root->right = new node('C');
    root->left->left = new node('D');
    root->left->right = new node('E');
    root->right->right = new node('F');

    cout << "Height of tree: " << height(root) << endl;

    return 0;
}

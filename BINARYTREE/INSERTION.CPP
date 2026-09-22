#include <iostream>
#include <vector>
#include <queue>
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

Node* insertion(Node* root, int value) {

    Node* newNode = new Node(value);

    if (root == NULL) {
        return newNode;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* curr = q.front();
        q.pop();

        if (curr->left == NULL) {
            curr->left = newNode;
            return root;
        }
        else {
            q.push(curr->left);
        }

        if (curr->right == NULL) {
            curr->right = newNode;
            return root;
        }
        else {
            q.push(curr->right);
        }
    }

    return root;
}

void display(Node* root) {

    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        int n = q.size();

        for (int i = 0; i < n; i++) {

            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }

        cout << endl;
    }
}

int main() {

    Node* root = NULL;

    vector<int> values = {1, 2, 3, 4, 5, 6, 7};
   for (int i = 0; i < values.size(); i++) {
        root = insertion(root, values[i]);
    }

    cout << "\nBinary Tree:\n";
    display(root);

    return 0;
}
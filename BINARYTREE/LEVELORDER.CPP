#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;

        if (root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            
            vector<int> visited;
            int level = q.size();

            for (int i = 0; i < level; i++) {
                
                TreeNode* curr = q.front();
                q.pop();

                visited.push_back(curr->val);

                if (curr->left != NULL) {
                    q.push(curr->left);
                }

                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }

            result.push_back(visited);
        }

        return result;
    }
};

int main() {
   
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left= new TreeNode(4);
     root->left->right= new TreeNode(5);
    root->left->left->left= new TreeNode(8);
     root->left->left->right= new TreeNode(9);

    Solution s;

    vector<vector<int>> ans = s.levelOrder(root);

    for (auto level : ans) {
        cout << "[ ";
        for (int x : level) {
            cout << x << " ";
        }
        cout << "] ";
    }

    return 0;
}
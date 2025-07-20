#include <iostream>
#include <vector>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void f1(TreeNode* node, vector<int>& ans, int level) {
        if (node == NULL) {
            return;
        }

        if (level == ans.size()) {
            ans.push_back(node->val);
        }

        // Visit right before left to capture rightmost view
        f1(node->right, ans, level + 1);
        f1(node->left, ans, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        f1(root, ans, 0);
        return ans;
    }

    void f2(TreeNode* node, vector<int>& ans, int level) {
        if (node == NULL) {
            return;
        }

        if (level == ans.size()) {
            ans.push_back(node->val);
        }

        // Visit right before left to capture rightmost view
        f2(node->left, ans, level + 1);
        f2(node->right, ans, level + 1);
    }

    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans;
        f2(root, ans, 0);
        return ans;
    }
};

int main() {
    // Construct the binary tree:
    //        1
    //       / \
    //      2   3
    //       \   \
    //        5   4

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result1 = sol.rightSideView(root);
    vector<int> result2 = sol.leftSideView(root);

    cout << "Right side view of the binary tree: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Left side view of the binary tree: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    // Optional: Free memory
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

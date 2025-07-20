#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool f(TreeNode* n1, TreeNode* n2) {
        if (n1 == NULL || n2 == NULL) {
            return n1 == n2;
        }
        if (n1->val != n2->val) {
            return false;
        }
        bool l = f(n1->left, n2->right);
        bool r = f(n1->right, n2->left);
        return l && r;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return f(root->left, root->right);
    }
};

int main() {
    // Symmetric tree example:
    //        1
    //       / \
    //      2   2
    //     / \ / \
    //    3  4 4  3

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));

    Solution sol;
    bool result = sol.isSymmetric(root);

    cout << "The tree is " << (result ? "symmetric." : "not symmetric.") << endl;

    // Optional: Free memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

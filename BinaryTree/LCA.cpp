#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)
        {
            return root;
        }

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left==NULL)
        {
            return right;
        }
        else if(right==NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
};

int main() {
    // Construct the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Assign p and q
    TreeNode* p = root->left;             // Node with value 5
    TreeNode* q = root->left->right->right; // Node with value 4

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    else
        cout << "Lowest Common Ancestor not found." << endl;

    return 0;
}

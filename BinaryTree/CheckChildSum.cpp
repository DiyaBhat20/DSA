#include <iostream>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int checkChildrenSum(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return 1;
        }

        int leftVal = root->left ? root->left->val : 0;
        int rightVal = root->right ? root->right->val : 0;

        if (root->val != leftVal + rightVal) {
            return 0;
        }

        return checkChildrenSum(root->left) && checkChildrenSum(root->right);
    }
};

int main() {
    /*
       Constructing the following tree:
               10
              /  \
             8    2
            / \
           3   5
       This satisfies the children sum property.
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution sol;
    if (sol.checkChildrenSum(root)) {
        cout << "The tree satisfies the children sum property." << endl;
    } else {
        cout << "The tree does NOT satisfy the children sum property." << endl;
    }

    return 0;
}

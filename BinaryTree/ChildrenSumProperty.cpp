#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



class Solution {
public:
    // Function to change the values of the nodes
    // based on the sum of its children's values.
    void changeTree(TreeNode* root) {
        // Base case: If the current node
        // is NULL, return and do nothing.
        if (root == NULL) {
            return;
        }

        // Calculate the sum of the values of
        // the left and right children, if they exist.
        int child = 0;
        if (root->left) {
            child += root->left->val;
        }
        if (root->right) {
            child += root->right->val;
        }

        if (child >= root->val) {
            root->val = child;
        } else {
            if (root->left) {
                root->left->val = root->val;
            }
            if (root->right) {
                root->right->val = root->val;
            }
        }

        changeTree(root->left);
        changeTree(root->right);

        int tot = 0;
        if (root->left) {
            tot += root->left->val;
        }
        if (root->right) {
            tot += root->right->val;
        }

        if (root->left or root->right) {
            root->val = tot;
        }
    }
};


// Function to print the inorder
// traversal of the tree
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    // Print the inorder traversal
    // of tree before modification
    cout << "Binary Tree before modification: ";
    inorderTraversal(root);
    cout << endl;

    // Call the changeTree function
    // to modify the binary tree
    sol.changeTree(root);

    // Print the inorder traversal
    // after modification
    cout << "Binary Tree after Children Sum Property: " ;
    inorderTraversal(root);
    cout << endl;

    return 0;
}
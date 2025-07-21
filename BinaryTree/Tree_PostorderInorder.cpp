#include <iostream>
#include <vector>
#include <map>
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
    TreeNode* createTree(vector<int>& postorder, int ps, int pe, vector<int>& inorder, int is, int ie, map<int, int>& inmap) {
        if (ps > pe || is > ie) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[pe]);

        int index = inmap[root->val];
        int numsleft = index - is;

        root->left = createTree(postorder, ps, ps + numsleft - 1, inorder, is, index - 1, inmap);
        root->right = createTree(postorder, ps + numsleft, pe - 1, inorder, index + 1, ie, inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }

        return createTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);        
    }
};

// Helper function to print the tree in inorder traversal
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;

    // Sample input
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
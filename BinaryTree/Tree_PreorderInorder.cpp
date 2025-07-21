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
    TreeNode* createTree(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, map<int, int>& inmap) {
        if (prestart > preend || instart > inend) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);

        int index = inmap[root->val];
        int numsleft = index - instart;

        root->left = createTree(preorder, prestart + 1, prestart + numsleft, inorder, instart, index - 1, inmap);
        root->right = createTree(preorder, prestart + numsleft + 1, preend, inorder, index + 1, inend, inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }

        return createTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
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
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}

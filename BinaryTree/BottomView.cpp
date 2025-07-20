#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Binary Tree Node definition
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> bottomView(Node* root) {
        vector<int> result;
        if (!root) return result;

        // Map to store the first node at each horizontal distance (HD)
        map<int, int> topNode;
        // Queue to hold nodes with their horizontal distances
        queue<pair<Node*, int>> q;

        q.push({root, 0}); // root has horizontal distance 0

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            Node* node=p.first;
            int line=p.second;

            // Insert only the first node encountered at each HD
            topNode[line] = node->data;

            if (node->left) q.push({node->left, line - 1});
            if (node->right) q.push({node->right, line + 1});
        }

        for (auto p : topNode) {
            result.push_back(p.second);
        }

        return result;
    }
};


int main() {
    // Constructing the binary tree:
    //       1
    //      / \
    //     2   3
    //      \
    //       4
    //        \
    //         5
    //          \
    //           6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    Solution sol;
    vector<int> top_view = sol.bottomView(root);

    cout << "Top view of the binary tree: ";
    for (int val : top_view) {
        cout << val << " ";
    }
    cout << endl;

    // Memory cleanup (optional for small test programs)
    delete root->left->right->right->right;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
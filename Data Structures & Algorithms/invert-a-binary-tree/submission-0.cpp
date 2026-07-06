/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void DFS(TreeNode *root) {
        TreeNode *left = root->left;
        root->left = root->right;
        root->right = left;
        if (root->left) DFS(root->left);
        if (root->right) DFS(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        // to invert a tree, we want to swap each node's left subtree with right subtree
        if (!root) return root;
        DFS(root);
        return root;

    }
};

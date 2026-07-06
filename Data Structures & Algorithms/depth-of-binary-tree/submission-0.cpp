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
    int maxDepth(TreeNode* root) {

        if (!root) return 0;
        // BFS, the last node reached will have the most height
        queue<pair<TreeNode *, int>> q;

        int height = 1;
        q.push({root, height});
        while (!q.empty()) {
            auto [n, h] = q.front();
            height = h;
            q.pop();
            if (n->left) q.push({n->left, h + 1});
            if (n->right) q.push({n->right, h + 1});
        }
        return height;
    }
};

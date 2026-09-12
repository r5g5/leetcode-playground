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
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            return 1 + max(dfs(root->left), dfs(root->right));
        }
    }
public:
    int maxDepth(TreeNode* root) {
        return dfs(root); // TC: O(n+m), SC: O(n)
    }
};
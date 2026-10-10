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
private:
    void dfs(TreeNode* node, int maxSeen, int& cnt) {
        if (!node) return;
        if (node->val >= maxSeen) {
            cnt++;
        }
        dfs(node->left, max(maxSeen, node->val), cnt);
        dfs(node->right, max(maxSeen, node->val), cnt);
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, root->val, count);
        return count; // TC: O(n+m), SC: O(n)
    }
};
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
    long long totalSum = 0;
    void dfs(TreeNode* head, int currVal) {
        if (!head)
            return;
            
        if (head && (head->left == nullptr) && (head->right == nullptr)) {
            // leaf node
            currVal = (currVal << 1) | head->val;
            totalSum += currVal;
        } else {
            currVal = (currVal << 1) | (head->val);
            dfs(head->left, currVal);
            dfs(head->right, currVal);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return totalSum;
    }
};
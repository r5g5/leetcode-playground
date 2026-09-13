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
    TreeNode* find(TreeNode* root, const int val) {
        if (root == nullptr) {
            return nullptr;
        } else {
            if (root->val == val) {
                return root;
            } else if (root->val > val) {
                return find(root->left, val);
            }
            return find(root->right, val);
        }
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return find(root, val); // TC: O(log2(n)), SC: (1)
    }
};
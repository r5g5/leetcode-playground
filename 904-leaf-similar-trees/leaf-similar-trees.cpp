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
    void getLeafNodes(vector<int>& leafs, TreeNode* head) {
        if (!head) return;
        if (head->left == nullptr && head->right == nullptr) {
            leafs.emplace_back(head->val);
            return;
        }
        getLeafNodes(leafs, head->left);
        getLeafNodes(leafs, head->right);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1, leafs2;
        getLeafNodes(leafs1, root1);
        getLeafNodes(leafs2, root2);

        if (leafs1.size() != leafs2.size()) return false;

        return leafs1 == leafs2; // TC: O(n+m), SC: O(n)
    }
};
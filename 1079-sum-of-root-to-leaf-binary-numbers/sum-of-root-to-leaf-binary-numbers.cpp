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
    void dfs(TreeNode* head, string curr) {
        if (!head)
            return;
        if (head && (head->left == nullptr) && (head->right == nullptr)) {
            // leave node
            const auto sum = stoll(curr + to_string(head->val), nullptr, 2);
            totalSum += sum;
            // cout << sum << endl;
        } else {
            dfs(head->left, curr + to_string(head->val));
            dfs(head->right, curr + to_string(head->val));
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, "");
        return totalSum;
    }
};
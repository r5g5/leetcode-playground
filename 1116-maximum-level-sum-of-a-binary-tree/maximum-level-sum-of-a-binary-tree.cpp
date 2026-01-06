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
    struct NodeLevelInfo
    {
        TreeNode* node;
        const int level;
        NodeLevelInfo(TreeNode* n, const int lvl) : node(n), level(lvl) {}
    };
public:
    int maxLevelSum(TreeNode* root) {
        queue<NodeLevelInfo> q;
        q.push(NodeLevelInfo(root, 1));
        unordered_map<int, int> levelSumMap;
        while (!q.empty()) {
            NodeLevelInfo frontier = q.front(); q.pop();
            int currLevel = frontier.level;
            levelSumMap[currLevel] += frontier.node->val;
            if (frontier.node->left)
                q.push(NodeLevelInfo(frontier.node->left, currLevel + 1));
            if (frontier.node->right)
                q.push(NodeLevelInfo(frontier.node->right, currLevel + 1));
        }
        int ans = INT_MIN, ansLevel = INT_MAX;
        for (auto& lvlSum : levelSumMap) {
            // 'ans = max(ans, lvlSum.second');
            if (lvlSum.second > ans) {
                ans = lvlSum.second;
                ansLevel = lvlSum.first;
            } else if (lvlSum.second == ans) {
                ansLevel = min(ansLevel, lvlSum.first);
            }
        }
        return ansLevel;
    }
};
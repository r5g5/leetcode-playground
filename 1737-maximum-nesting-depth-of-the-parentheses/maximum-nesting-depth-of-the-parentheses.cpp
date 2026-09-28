class Solution {
public:
    int maxDepth(string s) {
        int openBrackets = 0;
        int ans = 0;

        for (const auto& c : s) {
            if (c == '(') {
                openBrackets++;
            } else if (c == ')') {
                openBrackets--;
            }
            ans = max(ans, openBrackets);
        }

        return ans; // TC: O(n), SC: O(1)
    }
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string parentheses;

        auto backtrack = [&](auto&& backtrack, int openCnt, int closedCnt) -> void {
            if (openCnt == closedCnt && openCnt == n) {
                result.push_back(parentheses);
                return;
            } 

            if (openCnt < n) {
                parentheses.push_back('(');
                backtrack(backtrack, openCnt + 1, closedCnt);
                parentheses.pop_back();
            } 
            
            if (openCnt > closedCnt) {
                parentheses.push_back(')');
                backtrack(backtrack, openCnt, closedCnt + 1);
                parentheses.pop_back();
            }
        };

        backtrack(backtrack, 0, 0);

        return result; // TC: O(2^n), SC: (n)
    }
};
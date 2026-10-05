class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> scores;

        scores.push(0);

        for (const char c : s) {
            if (c == '(') {
                scores.push(0);
            } else {
                int top = scores.top(); scores.pop();
                int score = top == 0 ? 1 : 2 * top;
                scores.top() += score;
            }
        }

        return scores.top(); // TC: O(N), SC: O(N)
    }
};
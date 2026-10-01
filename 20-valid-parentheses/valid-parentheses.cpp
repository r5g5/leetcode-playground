class Solution {
    inline bool isOpen(const char c) {
        return ((c == '(') || (c == '[') || (c == '{'));
    }
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (const auto c : s) {
            if (isOpen(c)) {
                brackets.push(c);
            } else {
                if (c == ')') {
                    if (!brackets.empty() && brackets.top() == '(') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                } else if (c == ']') {
                    if (!brackets.empty() && brackets.top() == '[') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                } else {
                    if (!brackets.empty() && brackets.top() == '{') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                }
            }
        }

        return brackets.empty(); // TC: O(n), SC: O(n)
    }
};
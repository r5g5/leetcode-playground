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
                if (brackets.empty())
                    return false;
                
                char top = brackets.top();

                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{'))
                    return false;
                
                brackets.pop();
            }
        }

        return brackets.empty(); // TC: O(n), SC: O(n)
    }
};
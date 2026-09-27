class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        // 'A' represents as a boundary
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '(') {
                st.push('A');
            } else if (s[i] == ')') {
                // pop till 'A'; and reverse and push it back
                string rev;
                while (st.top() != 'A') {
                    rev.push_back(st.top());
                    st.pop();
                }
                st.pop(); // remove 'A'
                // cout << i << ": => " << rev << endl;
                for (const auto& c : rev) {
                    st.push(c);
                }
            } else {
                st.push(s[i]);
            }
        }
        s.clear();
        while (!st.empty()) {
            s.push_back(st.top()); st.pop();
        }
        reverse(s.begin(), s.end());
        return s; // TC: O(n^2), SC: O(n)
    }
};
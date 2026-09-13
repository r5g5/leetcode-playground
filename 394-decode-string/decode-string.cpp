class Solution {
public:
    string decodeString(string s) {
        stack<char> chrSt;
        stack<int> intSt;

        for (int i = 0, n = s.size(); i < n; i++) {
            if (isdigit(s[i])) {
                // push the digit(s) to the intSt
                int repl = 0;
                while (i < n && isdigit(s[i])) {
                    int digit = s[i] - '0';
                    repl = (repl * 10) + digit;
                    i++;
                }
                --i;
                intSt.push(repl);
            } else if (s[i] == '[') {
                chrSt.push('A'); // 'A' represents different level (like a deadend)
            } else if (s[i] == ']') {
                // pop out and add to ans
                // get the number number that will be multiplier
                int repl = intSt.top(); intSt.pop();
                cout << "REPL: " << repl << endl;
                string tmp;
                while (!chrSt.empty()) {
                    if (chrSt.top() == 'A') {
                        chrSt.pop();
                        break;
                    } 
                    tmp.push_back(chrSt.top()); chrSt.pop();
                }
                string repeat;
                reverse(tmp.begin(), tmp.end());
                for (int i = 0; i < repl; i++) {
                    repeat += tmp;
                }
                for (auto c : repeat) {
                    chrSt.push(c);
                }
            } else {
                chrSt.push(s[i]);
            }
        }

        string ans;

        while (!chrSt.empty()) {
            ans.push_back(chrSt.top()); chrSt.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans; // TC: O(n), SC: O(n)
    }
};
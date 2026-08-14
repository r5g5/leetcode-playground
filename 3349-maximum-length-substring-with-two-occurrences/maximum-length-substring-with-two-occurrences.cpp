class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_map<char, int> count;
                bool isValid = true;
                for (int k = i; k <= j; k++) {
                    count[s[k]]++;
                    if (count[s[k]] > 2) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans; // TC: O(n^3), SC: O(n)
    }
};
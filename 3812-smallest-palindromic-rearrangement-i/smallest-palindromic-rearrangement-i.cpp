class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mp;
        for (const char c : s) {
            mp[c]++;
        }
        const int n = s.size();
        int i = 0, j = n - 1; 

        for (auto& kvp : mp) {
            if (kvp.second & 1) {
                int mid = kvp.second / 2;
                for (int k = 0; k < mid; k++) {
                    s[i++] = kvp.first;
                }
                for (int k = 0; k < mid; k++) {
                    s[j--] = kvp.first;
                }
                s[n / 2] = kvp.first;
            } else {
                int mid = kvp.second / 2;
                for (int k = 0; k < mid; k++) {
                    s[i++] = kvp.first;
                }
                for (int k = 0; k < mid; k++) {
                    s[j--] = kvp.first;
                }
            }
        }

        return s; // TC: O(n), SC: O(n)
    }
};
class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mp;
        for (const auto& ch : s) {
            mp[ch]++;
        }
        int i = 0, j = s.size() - 1;

        for (auto& [ch, cnt] : mp) {
            int half = cnt / 2;
            while (half--) {
                s[i++] = ch;
                s[j--] = ch;
            }

            if (cnt & 1) {
                s[s.size() / 2] = ch;
            }
        }

        return s; // TC: O(n), SC: O(n)
    }
};
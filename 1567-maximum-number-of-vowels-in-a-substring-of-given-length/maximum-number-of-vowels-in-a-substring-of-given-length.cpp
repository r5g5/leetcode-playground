class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) count++;
        }
        int ans = count;
        for (int i = k, n = s.size(); i < n; i++) {
            if (vowels.count(s[i-k])) count--;
            if (vowels.count(s[i])) count++;
            ans = max(ans, count);
        }
        return ans; // TC: O(n), SC: O(1)
    }
};
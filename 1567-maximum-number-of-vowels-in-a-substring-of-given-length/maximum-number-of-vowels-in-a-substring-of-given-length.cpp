class Solution {
private:
    inline bool isVowel(const char& c) {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
    }
public:
    int maxVowels(string s, int k) {
        int vowelCnt = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) vowelCnt++;
        }
        int ans = vowelCnt;
        for (int i = k, n = s.size(); i < n; i++) {
            if (isVowel(s[i-k])) vowelCnt--;
            if (isVowel(s[i])) vowelCnt++;
            ans = max(ans, vowelCnt);
        }
        return ans; // TC: O(n), SC: O(1)
    }
};
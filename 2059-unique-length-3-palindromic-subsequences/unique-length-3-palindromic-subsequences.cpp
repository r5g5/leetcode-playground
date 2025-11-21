class Solution {
    struct PairHash {
        size_t operator()(const pair<char,char>& p) const noexcept {
            return ((size_t)p.first << 8) ^ p.second;
        }
    };
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<pair<char,char>, PairHash> res;

        unordered_set<char> left;
        unordered_map<char, int> right;

        for (const char& c : s) {
            right[c]++;
        }

        for (const char& mid : s) {
            right[mid] -= 1;

            for (const char& c : left) {
                if (right[c] > 0) {
                    res.insert({c, mid});
                }
            }

            left.insert(mid);
        }

        return res.size();
    }
};
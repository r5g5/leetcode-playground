class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> codeSet;
        for (int i = 0, n = s.size() - k + 1; i < n; i++) {
            const string code = s.substr(i, k);
            codeSet.insert(code);
        }
        return codeSet.size() == 1 << k;
    }
};
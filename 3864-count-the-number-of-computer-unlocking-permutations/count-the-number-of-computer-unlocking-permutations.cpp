class Solution {
    const int _mod;
public:
    Solution() : _mod((int) 1e9 + 7) {}
    int countPermutations(vector<int>& complexity) {
        if (*min_element(complexity.begin() + 1, complexity.end()) <= complexity[0])
            return 0;
        long long ans = 1;
        for (int i = 1, n = complexity.size(); i < n; i++) {
            ans = (ans * i) % _mod;
        }
        return static_cast<int>(ans);
    }
};
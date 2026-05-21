class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> allPrefix;
        for (auto x : arr1) {
            for (; x; x/=10) {
                allPrefix.insert(x);
            }
        }

        int ans = 0;

        for (auto x : arr2) {
            for (; x ; x /=10) {
                if (allPrefix.find(x) == allPrefix.end())
                    continue;
                ans = max(ans, x);
            }
        }

        // cout << ans << endl;

        return ans > 0 ? log10(ans) + 1 : 0;
    }
};
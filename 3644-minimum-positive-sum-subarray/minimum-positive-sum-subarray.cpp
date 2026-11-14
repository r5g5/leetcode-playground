class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for (int i = 0, n = nums.size(); i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j - i + 1 >= l && j - i + 1 <= r) {
                    int sum = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
                    if (sum > 0) {
                        ans = min(ans, sum);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans; // TC: O(n^3), SC: O(1)
    }
};
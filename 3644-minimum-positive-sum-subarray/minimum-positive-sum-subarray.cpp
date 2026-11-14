class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for (int i = 0, n = nums.size(); i < n; i++) {
            int sum = 0;
            for (int j = i; j < n && j - i + 1 <= r; j++) {
                sum += nums[j];
                if (j - i + 1 >= l && sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans; // TC: O(n^2), SC: O(1)
    }
};
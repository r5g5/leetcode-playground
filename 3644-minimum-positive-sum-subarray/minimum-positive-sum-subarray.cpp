class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        optional<int> ans;
        for (int i = 0, n = nums.size(); i < n; i++) {
            int sum = 0;
            for (int j = i; j < n && j - i + 1 <= r; j++) {
                sum += nums[j];
                if (j - i + 1 >= l && sum > 0)
                    ans = ans ? min(*ans, sum) : sum;
            }
        }
        return ans.value_or(-1); // TC: O(n^2), SC: O(1)
    }
};
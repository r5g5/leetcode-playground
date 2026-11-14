class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        optional<int> ans;
        for (int i = 0, n = nums.size(); i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j - i + 1 >= l && j - i + 1 <= r) {
                    int sum = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
                    if (sum > 0)
                        ans = ans ? min(*ans, sum) : sum;
                }
            }
        }
        return ans.value_or(-1); // TC: O(n^3), SC: O(1)
    }
};
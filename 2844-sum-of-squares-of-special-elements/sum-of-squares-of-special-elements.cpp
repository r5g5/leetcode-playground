class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (n % (i+1) == 0) {
                ans += (nums[i] * nums[i]);
            }
        }
        return ans; // TC: O(n), SC: O(1)
    }
};
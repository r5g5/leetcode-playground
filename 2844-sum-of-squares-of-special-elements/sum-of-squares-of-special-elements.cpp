class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        for (int i = 1, n = nums.size(); i*i <= n; i++) {
            if (n % i == 0) {
                // divisors are i and n / i
                ans += (nums[i-1] * nums[i-1]);
                if (i*i != n) {
                    ans += nums[n/i-1] * nums[n/i-1];
                }
            }
        }
        return ans; // TC: O(sqrt(n)), SC: O(1)
    }
};
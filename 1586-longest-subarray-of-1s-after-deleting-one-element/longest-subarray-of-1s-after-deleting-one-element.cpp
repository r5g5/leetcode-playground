class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int longestWindow = 0, start = 0, noOfZeroes = 0;

        for (int i = 0, n = nums.size(); i < n; i++) {
            noOfZeroes += nums[i] == 0;

            while (noOfZeroes > 1) {
                noOfZeroes -= (nums[start] == 0);
                start++;
            }

            longestWindow = max(longestWindow, i - start);
        }

        return longestWindow; // TC: O(n), SC: O(1)
    }
};
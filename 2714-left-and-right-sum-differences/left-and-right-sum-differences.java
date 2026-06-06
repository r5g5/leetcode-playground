class Solution {
    public int[] leftRightDifference(int[] nums) {
        final int n = nums.length;
        int[] ans = new int[n];
        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            ans[i] = leftSum;
            leftSum += nums[i];
        }
        int rightSum = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = Math.abs(ans[i] - rightSum);
            rightSum += nums[i];
        }
        return ans; // TC: O(n), SC: O(1) / O(n) [depending on wheter we consider the output to be part of space complexity]
    }
}
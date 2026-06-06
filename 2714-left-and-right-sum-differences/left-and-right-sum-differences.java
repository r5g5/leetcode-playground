class Solution {
    private int getTotalRightSum(int[] nums, int n) {
        int rightSum = 0;
        for (int i = n - 1; i > 0; i--) {
            rightSum += nums[i];
        }
        return rightSum;
    }
    public int[] leftRightDifference(int[] nums) {
        final int n = nums.length;
        int rightSum = getTotalRightSum(nums, n);
        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            if (i == 0) {
                nums[i] = Math.abs(leftSum - rightSum);
            }
            else {
                rightSum -= nums[i];
                nums[i] = Math.abs(leftSum - rightSum);
            }
            leftSum += tmp;
        }
        return nums; // TC: O(n), SC: O(1)
    }
}
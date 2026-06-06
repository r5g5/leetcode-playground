class Solution {
    public int[] leftRightDifference(int[] nums) {
        int suffixSum = 0;
        final int n = nums.length;
        int[] suffix = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                suffix[i] = suffixSum;
                suffixSum += nums[i];
            } else {
                suffix[i] = suffixSum;
                suffixSum += nums[i];
            }
        }
        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            suffix[i] = Math.abs(prefixSum - suffix[i]);
            prefixSum += nums[i];
        }

        return suffix;
    }
}
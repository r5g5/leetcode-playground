class Solution {
    public double findMaxAverage(int[] nums, int k) {
        final int n = nums.length;
        int[] sum = new int[n];
        sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i-1] + nums[i];
        }
        double res = (sum[k-1] * 1.0) / k;
        for (int i = k; i < n; i++) {
            double calcMean = ((sum[i] - sum[i-k]) * 1.0) / k;
            res = Math.max(res, calcMean);
        }
        return res; // TC: O(n), SC: O(n)
    }
}
class Solution {
    public int minElement(int[] nums) {
        int ans = Integer.MAX_VALUE;
        for (int digit : nums) {
            int sum = 0;
            while (digit > 0) {
                int rem = digit % 10;
                digit /= 10;
                sum += rem;
            }
            ans = Math.min(ans, sum);
        }
        return ans;
    }
}
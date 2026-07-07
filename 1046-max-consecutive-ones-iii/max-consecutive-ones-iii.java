class Solution {
    public int longestOnes(int[] nums, int k) {
        int l = 0, r = 0, max = 0, cnt = 0, n = nums.length;

        while (r < n) {
            cnt += (nums[r] ^ 1);
            if (cnt <= k) {
                max = Math.max(max, r - l + 1);
            } else {
                cnt -= nums[l] == 0 ? 1 : 0;
                l++;
            }
            r++;
        }

        return max; // TC: O(n), SC: O(1)
    }
}
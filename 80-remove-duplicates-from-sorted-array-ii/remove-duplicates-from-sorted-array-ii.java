class Solution {
    private void swap(int[] v, int i, int j) {
        v[j] = v[i];
        return;
    }
    public int removeDuplicates(int[] nums) {
        int j = 1, count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1]) {
                count++;
            } else {
                count = 1;
            }

            if (count > 2) {
                // save j here
            } else {
                swap(nums, i, j);
                j++;
            }
        }
        return j; // TC: O(n), SC: O(1)
    }
}
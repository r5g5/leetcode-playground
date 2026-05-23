class Solution {
    private boolean isSorted(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] >= nums[i-1])
                continue;
            return false;
        }
        return true;
    }
    public boolean check(int[] nums) {
        if (isSorted(nums))
            return true;

        final int n = nums.length;

        for (int i = 0; i < n; i++) {
            // First i elements at the back
            // final arr = [i + 1, ... n, 0 ... i]
            int[] tmp = new int[n];
            System.arraycopy(nums, i + 1, tmp, 0, n - i - 1);
            System.arraycopy(nums, 0, tmp, n - i - 1, i + 1);

            if (isSorted(tmp))
                return true;
        }

        return false;

        // return false;
    }
}
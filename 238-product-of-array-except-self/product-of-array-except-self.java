class Solution {
    public int[] productExceptSelf(int[] nums) {
        int noOfZeros = 0, product = 1;
        for (int num : nums) {
            if (num == 0) {
                noOfZeros++;
                continue;
            }
            product *= num;
        }
        if (noOfZeros >= 2) {
            // result contains all 0's now
            for (int i = 0; i < nums.length; i++) {
                nums[i] = 0;
            }
        } else if (noOfZeros == 1) {
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] == 0) {
                    nums[i] = product;
                    continue;
                }
                nums[i] = 0;
            }
        } else {
            for (int i = 0; i < nums.length; i++) {
                nums[i] = product / nums[i];
            }
        }
        return nums;
    }
}
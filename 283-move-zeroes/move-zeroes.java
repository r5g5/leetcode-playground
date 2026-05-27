class Solution {
    public void moveZeroes(int[] nums) {
        Deque<Integer> queue = new ArrayDeque<>();
        int noOfZeroes = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                queue.add(nums[i]);
            } else {
                noOfZeroes++;
            }
        }
        int idx = 0;
        while (!queue.isEmpty()) {
            int val = queue.poll();
            nums[idx++] = val;
            // break;
        }
        while (noOfZeroes > 0) {
            nums[idx++] = 0;
            noOfZeroes--;
        }
        return;
    }
}
class Solution {
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<Integer, Integer>();
        int ops = 0;
        for (int num : nums) {
            int rem = k - num;
            int remCnt = freq.getOrDefault(rem, 0);
            if (remCnt > 0) {
                ops++;
                if (remCnt == 1) freq.remove(rem);
                else freq.put(rem, remCnt - 1);
            } else {
                freq.merge(num, 1, Integer::sum);
            }
        }
        return ops; // TC: O(n), SC: O(n)
    }
}
class Solution {
    public int maxOperations(int[] nums, int k) {
        var intFreq = new HashMap<Integer, Integer>();
        for (int num : nums) {
            if (!intFreq.containsKey(num))
                intFreq.put(num, 0);
            final int frequency = intFreq.get(num);
            intFreq.put(num, frequency + 1);
        }
        int noOfOps = 0;
        for (int num : nums) {
            int rem = k - num;
            if ((intFreq.getOrDefault(rem, 0) > 0) && 
                (intFreq.getOrDefault(num, 0) > 0)) {
                if (rem == num) {
                    if (intFreq.getOrDefault(num, 0) < 2) continue;
                }
                intFreq.put(rem, intFreq.get(rem) - 1);
                intFreq.put(num, intFreq.get(num) - 1);
                noOfOps++;
            }
        }
        return noOfOps; // TC: O(n), SC: O(n)
    }
}
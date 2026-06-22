class Solution {
    private static int getMin(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("Invalid arguement passed");
        }
        int ans = nums[0];
        for (int num : nums) {
            ans = Math.min(num, ans);
        }
        return ans;
    }
    public int maxNumberOfBalloons(String text) {
        // final String balloon = "balloon"; // b -> 1, a -> 1, l -> 2, o -> 2, n -> 1
        var charToCntMap = new HashMap<Character, Integer>();
        for (char c : text.toCharArray()) {
            if (!charToCntMap.containsKey(c)) {
                charToCntMap.put(c, 0);
            }
            charToCntMap.put(c, charToCntMap.get(c) + 1);
        }
        return getMin(charToCntMap.getOrDefault('b', 0),
                      charToCntMap.getOrDefault('a', 0),
                      charToCntMap.getOrDefault('l', 0) / 2,
                      charToCntMap.getOrDefault('o', 0) / 2,
                      charToCntMap.getOrDefault('n', 0));
        
        // TC: O(n), SC: O(n)
    }
}
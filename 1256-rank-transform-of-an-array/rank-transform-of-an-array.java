class Solution {
    public int[] arrayRankTransform(int[] arr) {
        var numToRankMap = new HashMap<Integer, Integer>();
        int rank = 1;
        TreeSet<Integer> nums = new TreeSet<>();

        for (int num : arr) {
            nums.add(num);
        }

        for (int num : nums) {
            numToRankMap.put(num, rank++);
        }

        for (int i = 0; i < arr.length; i++) {
            arr[i] = numToRankMap.get(arr[i]);
        }

        return arr; // TC: O(nlogn), SC: O(n)
    }
}
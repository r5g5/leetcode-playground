class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        var count1 = new HashSet<Integer>();
        var count2 = new HashSet<Integer>();
        for (int num : nums1) {
            count1.add(num);
        }

        for (int num : nums2) {
            count2.add(num);
        }

        List<List<Integer>> result = new ArrayList<>();
        List<Integer> result1 = new ArrayList<>();
        List<Integer> result2 = new ArrayList<>();

        for (int num : nums2) {
            if (count1.contains(num))
                continue;
            else if (result1.contains(num))
                continue;
            result1.add(num);
        }

        for (int num : nums1) {
            if (count2.contains(num)) 
                continue;
            else if (result2.contains(num)) continue;
            result2.add(num);
        }
        result.add(result2);
        result.add(result1);
        return result;
    }
}
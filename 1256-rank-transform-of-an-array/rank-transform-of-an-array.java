class Solution {
    public int[] arrayRankTransform(int[] arr) {
        var rankMap = new HashMap<Integer, Integer>();
        int[] tmp = arr.clone();
        Arrays.sort(arr);
        int currRank = 1;
        for (int element : arr) {
            if (rankMap.containsKey(element))
                continue;
            rankMap.put(element, currRank++);
        }
        final int n = arr.length;
        int[] rank = new int[n];
        for (int i = 0; i < n; i++) {
            rank[i] = rankMap.get(tmp[i]);
        }

        return rank; // TC: O(nlogn), SC: O(N)
    }
}
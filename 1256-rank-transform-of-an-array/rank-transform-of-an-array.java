class Solution {
    public int[] arrayRankTransform(int[] arr) {
        final int n = arr.length;
        int[] sortedArray = Arrays.copyOf(arr, n);
        Arrays.sort(sortedArray);
        int rank = 1;
        var numToRankMap = new HashMap<Integer, Integer>();

        for (int i = 0; i < n; i++) {
            if (i > 0 && sortedArray[i] > sortedArray[i-1]) {
                rank++;
            }
            numToRankMap.put(sortedArray[i], rank);
        }

        for (int i = 0; i < n; i++) {
            arr[i] = numToRankMap.get(arr[i]);
        }

        return arr; // TC: O(nlogn), SC: O(n + S); S = sorting algorithm time complexity
    }
}
class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        // First sort it, then the answer is min(size, arr[size])
        final int n = arr.length;
        Arrays.sort(arr);        
        // First element must be 1, then all the next cons. elements must have a difference of at max 1.
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] >= cnt + 1) {
                cnt++;
            }
        }
        return cnt; // TC: O(nlogn), SC: O(logn)
    }
}
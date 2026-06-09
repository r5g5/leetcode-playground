class Solution {
    public long maxTotalValue(int[] nums, int k) {
        final long maxElement = Arrays.stream(nums).max().getAsInt();
        final long minElement = Arrays.stream(nums).min().getAsInt();
        return (maxElement - minElement) * k;
    }
}
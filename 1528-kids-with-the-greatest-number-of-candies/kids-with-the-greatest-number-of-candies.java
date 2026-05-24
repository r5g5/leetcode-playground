class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        var maxCandies = 0;
        for (var candie : candies) {
            maxCandies = Math.max(candie, maxCandies);
        }
        var result = new ArrayList<Boolean>(candies.length);
        for (var candie : candies) {
            result.add(candie + extraCandies >= maxCandies);
        }
        return result; // TC: O(n), SC: O(1) if we don't consider the output, else O(n)
    }
}
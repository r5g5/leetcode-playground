class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        final int maxCandies = IntStream.of(candies).max().orElse(0);
        var result = new ArrayList<Boolean>(candies.length);
        for (var candie : candies) {
            result.add(candie + extraCandies >= maxCandies);
        }
        return result;
    }
}
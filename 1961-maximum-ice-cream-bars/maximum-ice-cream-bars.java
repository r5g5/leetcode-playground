class Solution {
    public int maxIceCream(int[] costs, int coins) {
        final int n = (int) 1e5 + 1;
        int[] sortedCosts = new int[n];
        for (int cost : costs) {
            sortedCosts[cost]++;
        }
        int noOfItems = 0;
        for (int i = 1; i < n; i++) {
            final int canBuy = Math.min(sortedCosts[i], coins / i);
            coins -= canBuy * i;
            noOfItems += canBuy;
        }
        return noOfItems; // TC: O(n), SC: O(n)
    }
}
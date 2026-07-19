class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = INT_MAX, maxProfit = 0;
        for (int i = 0, n = prices.size(); i < n; i++) {
            minSoFar = min(minSoFar, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minSoFar);
        }
        return maxProfit; // TC: O(n), SC: O(1)
    }
};
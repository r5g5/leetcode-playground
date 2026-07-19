class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1, n = prices.size(), maxProfit = 0;

        while (r < n) {
            if (prices[r] > prices[l]) {
                int profit = prices[r] - prices[l];
                maxProfit = max(maxProfit, profit);
            } else {
                l = r;
            }
            r++;
        }

        return maxProfit;
    }
};
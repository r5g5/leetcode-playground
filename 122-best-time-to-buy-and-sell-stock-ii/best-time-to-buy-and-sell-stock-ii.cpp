class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        for (int sell = 1; sell < prices.size(); sell++) {
            int buy = sell - 1;
            if (prices[sell] > prices[buy]) {
                totalProfit += prices[sell] - prices[buy];
            }
        }
        return totalProfit; // TC: O(n), SC: O(1)
    }
};
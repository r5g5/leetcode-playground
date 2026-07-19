class Solution {
private:
    int dp[5001][2];
    int dfs(const vector<int>& prices, int day, bool buying) {
            if (day >= prices.size())
                return 0;
            if (dp[day][buying] != -1)
                return dp[day][buying];
            
            int cooldown = dfs(prices, day + 1, buying);
            
            if (buying) {
                int buy = dfs(prices, day + 1, !buying) - prices[day];
                dp[day][buying] = max(cooldown, buy);
            } else {
                int sell = dfs(prices, day + 2, !buying) + prices[day];
                dp[day][buying] = max(cooldown, sell);
            }

        return dp[day][buying];
    }

public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return dfs(prices, 0, true); // TC: O(n), SC: O(1)
    }
};
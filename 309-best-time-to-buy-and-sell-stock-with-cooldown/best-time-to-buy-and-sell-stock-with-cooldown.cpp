class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int dp[5001][2];
        memset(dp, -1, sizeof(dp));
        function<int(int, bool)> dfs = [&](int index, bool buying) -> int {
            if (index >= prices.size()) {
                return 0;
            }
            if (dp[index][buying] != -1) {
                return dp[index][buying];
            }
            if (buying) {
                int onBuying = dfs(index + 1, !buying) - prices[index];
                int onCoolDown = dfs(index + 1, buying);
                dp[index][buying] = max(onBuying, onCoolDown);
            } else {
                int onSelling = dfs(index + 2, !buying) + prices[index];
                int onCoolDown = dfs(index + 1, buying);
                dp[index][buying] = max(onSelling, onCoolDown);
            }
            return dp[index][buying];
        };
        return dfs(0, true);
    }
};
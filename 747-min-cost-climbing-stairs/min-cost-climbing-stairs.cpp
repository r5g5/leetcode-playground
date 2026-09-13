class Solution {
    int dp[1001];
    int solve(const int curr, const int top, const vector<int>& cost) {
        if (curr >= top) {
            return 0;
        } else if (dp[curr] != -1) {
            return dp[curr];
        } else {
            return dp[curr] = min(
                cost[curr] + solve(curr + 1, top, cost),
                cost[curr] + solve(curr + 2, top, cost)
            );
        }
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return min(solve(0, cost.size(), cost), solve(1, cost.size(), cost)); // TC: O(n), SC: O(n)
    }
};
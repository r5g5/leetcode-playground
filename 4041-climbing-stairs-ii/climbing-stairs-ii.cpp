class Solution {
    int dp[(int) 1e5 + 1];

    int minCost(const int curr, const int dest, const vector<int>& costs) {
        if (curr == dest) {
            return 0;
        } else if (dp[curr] != -1) {
            return dp[curr];
        } else {
            int minStep = INT_MAX;
            
            if (curr + 1 <= dest) {
                int cost1 = costs[curr] + 1 + minCost(curr + 1, dest, costs);
                minStep = min(cost1, minStep);
            } 
            
            if (curr + 2 <= dest) {
                int cost2 = costs[curr + 1] + 4 + minCost(curr + 2, dest, costs);
                minStep = min(cost2, minStep);
            } 
            
            if (curr + 3 <= dest) {
                int cost3 = costs[curr + 2] + 9 + minCost(curr + 3, dest, costs);
                minStep = min(cost3, minStep);
            }

            return dp[curr] = minStep;
        }
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return minCost(0, n, costs); // TC: O(n), SC: O(n)
    }
};
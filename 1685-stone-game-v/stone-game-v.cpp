class Solution {
    int dp[501][501];
    int prefixSum[501];
    int solve(int l, int r) {
        if (l == r) return 0;
        else if (dp[l][r] != -1) return dp[l][r];
        else {
            int ans = 0;
            for (int k = l+1; k <= r; k++) {
                int leftSum = prefixSum[k] - prefixSum[l]; // [l...k]
                int rightSum = prefixSum[r+1] - prefixSum[k]; // [k...r]
                if (leftSum < rightSum) {
                    ans = max(ans, leftSum + solve(l, k-1));
                } else if (rightSum < leftSum) {
                    ans = max(ans, rightSum + solve(k, r));
                } else {
                    ans = max({ans, leftSum + solve(l, k-1), rightSum + solve(k, r)});
                }
            }
            return dp[l][r] = ans;
        }
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        memset(dp, -1, sizeof(dp));
        memset(prefixSum, 0, sizeof(prefixSum));
        const int n = stoneValue.size();
        for (int i = 0; i < n; i++) {
            prefixSum[i+1] = prefixSum[i] + stoneValue[i];
        }
        return solve(0, n - 1); // TC: O(n^3), SC: O(n^2)
    }
};
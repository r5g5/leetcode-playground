class Solution {
private:
    int solve(int idx, int n, int prev1col, int prev2col, int prev3col, vector<vector<vector<vector<int>>>>& dp) {

        static const int mod = 1e9 + 7;
        if (idx == n)
            return 1;
        
        if (dp[idx][prev1col+1][prev2col+1][prev3col+1] != -1)
            return dp[idx][prev1col+1][prev2col+1][prev3col+1];

        int ans = 0;

        for (int col1 = 0; col1 < 3; col1++) {
            for (int col2 = 0; col2 < 3; col2++) {
                for (int col3 = 0; col3 < 3; col3++) {
                    if ((col1 != prev1col) && (col2 != prev2col) && (col3 != prev3col) &&
                    (col1 != col2) && (col2 != col3)) {
                        ans += solve(idx+1, n, col1, col2, col3, dp);
                        ans %= mod;
                    }
                }
            }
        }

        return dp[idx][prev1col+1][prev2col+1][prev3col+1] = ans;
    }
public:
    int numOfWays(int n) {
        
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4, -1)))
        );


        return solve(0, n, -1, -1, -1, dp);
    }
};
class Solution {
private:
    int dp[501][501];

    bool solve(const vector<int>& piles, int i, int j, int aliceScore, int bobScore, bool isAliceTurn) {
        if (i > j) {
            return aliceScore >= bobScore;
        } else if (dp[i][j] != -1) {
            return dp[i][j];
        } else {
            bool ok;
            int frontScore = piles[i];
            int backScore = piles[j];

            if (isAliceTurn) {
                ok = false;
                // option 1: alice takes from the front
                ok |= solve(piles, i + 1, j, aliceScore + frontScore, bobScore, !isAliceTurn);
                // option 2: alice takes from the back
                ok |= solve(piles, i, j - 1, aliceScore + backScore, bobScore, !isAliceTurn);
            } else {
                ok = true;
                ok |= solve(piles, i + 1, j, aliceScore, bobScore + frontScore, !isAliceTurn);
                ok |= solve(piles, i, j - 1, aliceScore, bobScore + backScore, !isAliceTurn);
            }
            dp[i][j] = ok ? 1 : 0;
            return ok;
        }
    }
public:
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solve(piles, 0, piles.size() - 1, 0, 0, true); // TC: O(n^2), SC: O(n^2)
    }
};
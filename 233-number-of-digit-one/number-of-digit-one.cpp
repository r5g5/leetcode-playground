class Solution {
private:
    int dp[10/* index */][2 /* tight */ ][10 /* cnt */];
    int solve(const string& s, int idx, bool tight, int cnt) {
        if (idx == s.size()) return cnt;
        if (dp[idx][tight][cnt] != -1) return dp[idx][tight][cnt];
        const int limit = tight ? s[idx] - '0' : 9;
        int ans = 0;
        for (int i = 0; i <= limit; i++) {
            int updateCnt = cnt + (i == 1 ? 1 : 0);
            ans += solve(s, idx + 1, tight & (i == s[idx] - '0'), updateCnt);
        }
        return dp[idx][tight][cnt] = ans;
    }
public:
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string r = to_string(n);
        return solve(r, 0, true, 0);
    }
};
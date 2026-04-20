class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        for (int l = 0, n = colors.size(); l < n; l++) {
            for (int r = 0; r < n; r++) {
                if (colors[l] != colors[r]) {
                    ans = max(ans, abs(r-l));
                }
            }
        }
        return ans;
    }
};
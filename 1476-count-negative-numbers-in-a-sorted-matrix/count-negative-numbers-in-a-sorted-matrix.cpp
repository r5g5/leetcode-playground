class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for (auto& row : grid) {
            for (auto& col : row) {
                if (col < 0)
                    ++cnt;
            }
        }
        return cnt;
    }
};
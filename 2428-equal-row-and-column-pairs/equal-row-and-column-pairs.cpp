class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        for (int row = 0, n = grid.size(); row < n; row++) {
            for (int col = 0; col < n; col++) {
                bool isMatch = true;
                for (int i = 0; i < n; i++) {
                    if (grid[row][i] != grid[i][col]) {
                        isMatch = false;
                        break;
                    }
                }
                count += isMatch ? 1 : 0;
            }
        }
        return count; // TC: O(n^3), SC: O(1)
    }
};
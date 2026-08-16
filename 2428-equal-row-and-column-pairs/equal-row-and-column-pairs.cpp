class Solution {
    bool isEqual(const vector<int>& rows, const vector<int>& columns, const int len) {
        for (int i = 0; i < len; i++) {
            if (rows[i] != columns[i])
                return false;
        }
        return true;
    }
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> allRows, allColumns;
        int totalEqPairs = 0, n = grid.size();
        for (int row = 0; row < n; row++) {
            vector<int> column;
            for (int col = 0; col < n; col++) {
                column.push_back(grid[col][row]);
            }
            allRows.push_back(grid[row]);
            allColumns.push_back(column);
        }

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                totalEqPairs += isEqual(allRows[r], allColumns[c], n);
            }
        }

        return totalEqPairs; // TC: O(n^3), SC: O(n)
    }
};
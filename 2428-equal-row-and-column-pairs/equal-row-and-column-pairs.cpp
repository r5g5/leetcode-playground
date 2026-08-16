class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rowCounter;
        int count = 0;
        for (auto& row : grid) {
            string s;
            for_each(row.begin(), row.end(), [&](const int x) -> void {s.append(std::to_string(x) + ",");});
            rowCounter[s]++;
        }

        for (int r = 0, n = grid.size(); r < n; r++) {
            vector<int> column;
            for (int c = 0; c < n; c++) {
                column.push_back(grid[c][r]);
            }
            string s;
            for_each(column.begin(), column.end(), [&](const int x) -> void {s.append(std::to_string(x) + ",");});
            if (rowCounter.find(s) != rowCounter.end()) {
                count += rowCounter[s];
            }
        }
        return count; // TC: O(n^2), SC: O(n)
    }
};
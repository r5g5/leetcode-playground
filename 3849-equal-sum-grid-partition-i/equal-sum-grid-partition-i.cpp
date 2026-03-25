class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        auto m = grid.size(), n = grid[0].size();
        vector<uint64_t> rowSum(m, 0), colSum(n, 0);
        uint64_t totalSumOfRows = 0, totalSumOfCols = 0;
        for (int i = 0; i < m; i++) {
            uint64_t totalSumAtRowI = accumulate(grid[i].begin(), grid[i].end(), 0LL);
            rowSum[i] = totalSumAtRowI;
            totalSumOfRows += totalSumAtRowI;
        }

        // do the same for columns
        for (uint64_t i = 0; i< n; i++) {
            uint64_t totalSumAtColI = 0;
            for (uint64_t j = 0; j < m; j++) {
                totalSumAtColI += grid[j][i];
            }
            colSum[i] = totalSumAtColI;
            totalSumOfCols += totalSumAtColI;
        }

        uint64_t rowSumTillNow = 0;
        // now, just iterate over the resultants
        for (const uint64_t& rowS : rowSum) {
            rowSumTillNow += rowS;

            if (rowSumTillNow == totalSumOfRows - rowSumTillNow)
                return true;
        }

        uint64_t colSumTillNow = 0;
        for (const uint64_t& colSum : colSum) {
            colSumTillNow += colSum;

            if (colSumTillNow == totalSumOfCols - colSumTillNow)
                return true;
        }

        return false;
    }
};
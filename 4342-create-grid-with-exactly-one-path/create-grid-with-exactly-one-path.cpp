class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        grid[0] = string(n, '.');

        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = '.'; 
        }

        return grid; // TC: O(m), SC: O(1) [ not considering o/p as part of space complexity]
    }
};
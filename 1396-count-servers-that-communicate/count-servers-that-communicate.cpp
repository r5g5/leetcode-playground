class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i = 0, m = grid.size(); i < m; i++) {
            for (int j = 0, n = grid[i].size(); j < n; j++) {
                if (grid[i][j] == 1) {
                    // there is a server at this coordinate [i, j]
                    // now just go to the same row and check if there is any other server with which it can communicate
                    // if not, then check for column too

                    // case1: row

                    int row = i, col = 0;
                    bool canCommunicate = false;

                    while (col < n) {
                        if (col != j) {
                            if (grid[row][col] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }
                        ++col;
                    }

                    if (canCommunicate) {
                        ++ans;
                    } else {
                        // case 2: check column
                        row = 0; col = j;
                        while (row < m) {
                            if (row != i) {
                                if (grid[row][col] == 1) {
                                    canCommunicate = true;
                                    break;
                                }
                            }
                            row++;
                        }

                        if (canCommunicate) {
                            ++ans;
                        }
                    }
                }
            }
        }

        return ans; // TC: O(m*n(m+n)), SC: O(1)
    }
};
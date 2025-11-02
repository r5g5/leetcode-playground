class Solution {
    enum Cell : char
    {
        GUARD = 'G',
        WALL = 'W',
        EMPTY = 'E'
    };
    bool _started = false;
    const std::array<int, 4> dRows = {-1, 1, 0, 0};
    const std::array<int, 4> dCols = {0, 0, -1, 1};

    void populateGuarded(vector<vector<bool>>& safe, vector<vector<Cell>>& jail, int cr, int cc) {
        // keep going north
        // safe[cr][cc] = true;

        for (int r = cr - 1; r >= 0; r--) {
            if (jail[r][cc] == Cell::WALL || jail[r][cc] == Cell::GUARD) {
                break;
            }
            safe[r][cc] = true;
        }

        // keep going south
        for (int r = cr + 1; r < jail.size(); r++) {
            if (jail[r][cc] == Cell::WALL || jail[r][cc] == Cell::GUARD)
                break;
            safe[r][cc] = true;
        }

        // keep going east
        for (int c = cc + 1; c < jail[0].size(); c++) {
            if (jail[cr][c] == Cell::WALL || jail[cr][c] == Cell::GUARD)
                break;
            safe[cr][c] = true;
        }

        // keep going west
        for (int c = cc - 1; c >= 0; c--) {
            if (jail[cr][c] == Cell::WALL || jail[cr][c] == Cell::GUARD)
                break;
            safe[cr][c] = true;
        }

        return;
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<Cell>> grid(m, vector<Cell>(n, Cell::EMPTY));
        for (auto& guard : guards) {
            int row = guard[0], col = guard[1];
            grid[row][col] = Cell::GUARD;
        }
        for (auto& wall : walls) {
            int row = wall[0], col = wall[1];
            grid[row][col] = Cell::WALL;
        }
        vector<vector<bool>> safety(m, vector<bool>(n, false));
        for (auto& guard : guards) {
            int row = guard[0], col = guard[1];
            _started = false;
            populateGuarded(safety, grid, row, col);
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!safety[i][j] && (grid[i][j] == Cell::EMPTY))
                    ++ans;
            }
        }
        return ans;
    }
};
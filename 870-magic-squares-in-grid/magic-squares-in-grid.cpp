class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        // center must be 5
        if (grid[r+1][c+1] != 5) return false;

        // check numbers 1 to 9 exactly once
        vector<bool> seen(10, false);
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || seen[val])
                    return false;
                seen[val] = true;
            }
        }

        // check rows
        for (int i = 0; i < 3; i++) {
            if (grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != 15)
                return false;
        }

        // check columns
        for (int j = 0; j < 3; j++) {
            if (grid[r][c+j] + grid[r+1][c+j] + grid[r+2][c+j] != 15)
                return false;
        }

        // check diagonals
        if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != 15)
            return false;

        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != 15)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};

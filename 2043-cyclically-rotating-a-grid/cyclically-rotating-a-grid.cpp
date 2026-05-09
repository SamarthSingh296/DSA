class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {

            vector<int> v;

            int top = layer;
            int left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

            // top row
            for (int j = left; j <= right; j++)
                v.push_back(grid[top][j]);

            // right column
            for (int i = top + 1; i <= bottom - 1; i++)
                v.push_back(grid[i][right]);

            // bottom row
            for (int j = right; j >= left; j--)
                v.push_back(grid[bottom][j]);

            // left column
            for (int i = bottom - 1; i >= top + 1; i--)
                v.push_back(grid[i][left]);

            // rotate left
            int len = v.size();
            int rot = k % len;

            rotate(v.begin(), v.begin() + rot, v.end());

            int idx = 0;

            // fill top row
            for (int j = left; j <= right; j++)
                grid[top][j] = v[idx++];

            // fill right column
            for (int i = top + 1; i <= bottom - 1; i++)
                grid[i][right] = v[idx++];

            // fill bottom row
            for (int j = right; j >= left; j--)
                grid[bottom][j] = v[idx++];

            // fill left column
            for (int i = bottom - 1; i >= top + 1; i--)
                grid[i][left] = v[idx++];
        }

        return grid;
    }
};
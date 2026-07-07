class Solution {
public:
    int ans = 0;

    int n;
    int m;

    vector<pair<int, int>> dirn = {
                    {-1, 0},
            {0, -1},        {0, 1},
                    {1, 0}
    };

    int dfs(int r, int c, auto& g) {
        g[r][c] = 0;

        int acc = 1;
        for (auto& [i, j] : dirn) {
            int nr = r + i;
            int nc = c + j;

            if (nr < 0 || nr >= m || nc < 0 || nc >= n || g[nr][nc] == 0) continue;
            acc += dfs(nr, nc, g);
        }

        return acc;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid[0].size();    
        m = grid.size();    

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    ans = max(ans, dfs(i, j, grid));
                } 
            }
        }

        return ans;
    }
};

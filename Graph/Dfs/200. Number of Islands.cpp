class Solution {
public:

    vector<pair<int,int>> dirn = {
                    {-1, 0},
        {0, -1},           {0, 1},
                    {1, 0}, 
    };

    
    void dfs(int r, int c, auto& g) {
        int m = g.size();
        int n = g[0].size();
        if (r >= m || c >= n || r < 0 || c < 0) return;               <-- redundand
        
        g[r][c] = '0';

        

        for (auto& [i, j] : dirn) {
            int nr = r + i;
            int nc = c + j;

            if (nr >= m || nc >= n || nr < 0 || nc < 0 || g[nr][nc] == '0') continue;
            dfs(nr, nc, g);
        }
        
    }


    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }

        return cnt;
    }
};

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        int target = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) 
                    q.push({i, j});

                else if (grid[i][j] == 1) 
                    target++;
            }
        }

        if (target == 0) return 0;

    

        int dirn[4][2] = {
                    {-1, 0}, 
            {0, -1},         {0, 1}, 
                    {1, 0}
        };


        int t = 0;

        while (!q.empty()) {
            
            int sz = q.size();

            while (sz--) {
                auto [i, j] = q.front(); q.pop();          <-- no '&' since pop destroy the ref mem later ref can raise error 'ref freed mem'
                
                for (auto& d : dirn) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if (ni >= m || nj >= n || ni < 0 || nj < 0 || grid[ni][nj] != 1) continue;
                    target--;
                    grid[ni][nj] = 2;

                    q.push({ni, nj});
                }
            }
            t++;
        }

        return target == 0 ? t - 1 : -1;   // at last t still got incremented so we do -1


    }
};

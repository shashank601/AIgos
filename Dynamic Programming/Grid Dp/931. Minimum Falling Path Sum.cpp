class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int c = 0; c < n; c++) {
            dp[0][c] = matrix[0][c];
            // cout << "run";
        } 
        



        for (int r = 1; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int right = c == n - 1 ? INT_MAX : dp[r - 1][c + 1];
                int left = c == 0 ? INT_MAX : dp[r - 1][c - 1];

                dp[r][c] = min({dp[r - 1][c], left , right}) + matrix[r][c];
                // ans = min(ans, dp[r][c]);
                // cout << ans << endl;
                // cout << "run" << endl;
                if (r == n - 1) {
                    // ans = INT_MAX;
                    ans = min(ans, dp[r][c]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[n - 1][i]);
        }

        cout << ans << endl;

        return ans;
    }
};

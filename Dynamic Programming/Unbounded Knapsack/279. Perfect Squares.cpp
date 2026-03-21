class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int num = 1; num <= n; num++) {

            for (int sq = 1; sq * sq <= num; sq++) {                             <-- perfect squares ≤ num: 1², 2², 3²
                if (num - sq * sq < 0 || dp[num - sq*sq] == INT_MAX) continue;
                dp[num] = min(dp[num], dp[num - sq*sq] + 1);
            }
        }

        return dp[n];
    }
};

===
for recursive style 
i can compute a cost array: conating all perf sq.
then recur can just take/skip assuming inf supply

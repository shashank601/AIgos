
class Solution {
public:
    int g(int idx, int amount, vector<int>& coins, auto& dp) {  <--- cant decrese the dimension   (idx is needed to knwo which coin im allowed to use)
        if (amount <= 0 || idx == coins.size()) {
            if (amount == 0) return 1;
            return 0;
        }
        if (dp[idx][amount] != -1) return dp[idx][amount];

        int ways = 0;

        ways += g(idx + 1, amount, coins, dp);
        // 
        ways += g(idx, amount - coins[idx], coins, dp);   // g(idx, amount) = g(idx + 1, amount) + g(idx, amount - coin[idx])

        return dp[idx][amount] = ways;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        return g(0, amount, coins, dp);
    }
};



====

felt hacky;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);     <-- cant predict this type w/o seeing an error msg
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return dp[amount];
    }
};


===
wrong way:
for each amount:
    try all coins

So sequences like:

2 + 3
3 + 2
    
coin outer = restrict decision order

  
====
a for loop style recusiron w/o idx fails due to ordering issues
====

Recursive DP:
stores decisions explicitly → needs more dimensions

Iterative DP:
encodes decisions in execution order → fewer dimensions

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);    <---- INT_MAX bcz  of min()
        dp[0] = 0;

        for (int amt = 1; amt <= amount; amt++) {     <--- unbounded knapsack "dont picks", it builds from smaller problem (like lis)
          
            for (auto& coin : coins) {
                if (amt - coin >= 0 && dp[amt - coin] != INT_MAX) {
                    dp[amt] = min(dp[amt], dp[amt - coin] + 1);
                }
            }

        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

===
finalyy:
do not try to simulate the process in unbounded knapsack

State:
dp[x] = answer for amount x

Transition:
dp[x] = combine(dp[x - something])
Every value is formed by adding one choice to a smaller solved value

dp[x] = best over all choices:
        (answer for x - choice) + cost_of_choice

=====
not optimal:
class Solution {
public:
    // add memo
    int g(vector<int>& coins, int target, int idx) {
        if (idx >= coins.size()) {
            if (target == 0) return 0;
            return -1; 
        }
        int count = INT_MAX;
        int res = -1;

        for (int i = 0; i <= (target/coins[idx]); i++) {
            // cout << i << " " << target/coins[idx] << '\n';
            res = g(coins, target - i * coins[idx], idx + 1);
            if (res == -1)  continue;   
            count = min(i + res, count);
            
        }
        if (res == -1) return res;

        return count == INT_MAX ? -1 : count;

    }
    int coinChange(vector<int>& coins, int amount) {
       
        return g(coins, amount, 0);
    }
};


====
TLE
class Solution {
public:
    vector<int> dp;
    Solution() {
        dp.assign(10'000, -1);
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount <= 0) {
            if (amount == 0) return 0;
            return -1;
        }
        if (dp[amount] != -1) return dp[amount];
        int ans = INT_MAX;        
        for (auto coin : coins) {
            int val = coinChange(coins, amount - coin);
            if (val == -1) continue;

            ans = min(ans, val + 1);
        }

        return dp[amount] = (ans == INT_MAX ? -1 : ans);
    }
};

===
the issue was i failed to categorize this problem correctly.
Unbounded knapsack and not generic linear dp


the remaining amount.
and not idx
memoize on the wrong thing (like idx only), the recursion explodes

Think in terms of building up answers instead of “trying all options”

Recursive approach: “Try 0…k coins of this type, then recurse” → easy to imagine, but exponentially many combinations.
Bottom-up approach: “I know the answer for smaller amounts, can I use it to get the answer for this amount?” → linear in amount × number of coins.
====
You think:

pick coin 1 → recurse
pick coin 2 → recurse
pick coin 3 → recurse

Problem:

Different sequences lead to the same remaining amount

Example:

11 → (pick 1, then 2, then 2, then 6…)
11 → (pick 2, then 1, then 2, then 6…)

Different paths, same subproblem:            <---- thats why i got TLE, this is not a optimal path problem

remaining = 6

You recompute it.

===

You are modeling:

state = sequence of picks

But the problem only depends on:

state = remaining amount
===

You are still thinking in terms of picking.
Unbounded knapsack is not about picking.

It is about:
evaluating all ways to form current state using smaller states

===
Not:
"pick a coin"

But:
"try every choice as the LAST step to build current amount"

  
====
You were solving:
“How many ways can I pick counts of coins?”

Instead of:
“What’s the best answer for smaller amounts and reuse it?”


===

    take (inf supply)
    skip

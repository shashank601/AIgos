class Solution {
public:
    int g(auto& days, auto& costs, int idx, auto& dp) {
        if (idx >= days.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int currDay = days[idx];
        int newDay = currDay;
        int newIdx = idx + 1;

        
        int a = costs[0] + g(days, costs, newIdx, dp);

        newDay = currDay + 6;
        newIdx = idx + 1;
        while (newIdx < days.size() && days[newIdx] <= newDay) newIdx++;
        int b = costs[1] + g(days, costs, newIdx, dp);
        
        
        newDay = currDay + 29;
        newIdx = idx + 1;
        while (newIdx < days.size() && days[newIdx] <= newDay) newIdx++;
        int c = costs[2] + g(days, costs, newIdx, dp);

        return dp[idx] = min({a, b, c});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(365, -1);
        return g(days, costs, 0, dp);
    }
};


====
  just simulate choices;
====
  two improvements
  use binary searhc
  use dyas.size for dp vector
====


f(i) = min(
    cost[0] + f(i+1),
    cost[1] + f(next index after 7-day coverage),
    cost[2] + f(next index after 30-day coverage)
)

===

  
Unbounded knapsack is NOT:

❌ “always subtract and fill dp array”
❌ “always pick/skip item”

It is:

“You can reuse choices unlimited times, and your state transitions must form valid smaller subproblems.”

=====
  
Backtracking categories → give you code shape
Subsets, permutations, combinations — the code is nearly copy-paste. Category = template. That's a tight mapping.
  
DP categories →

| What categories are for      | What categories are NOT for |
| ---------------------------- | --------------------------- |
| Recognizing state type fast  | Giving you copy-paste code  |
| Knowing transition direction | Guaranteeing loop order     |
| Ruling out wrong approaches  | Replacing your own thinking |

okk

===

old attempt:
(unoptimal)

class Solution {
public:
    int g(auto& dp, auto& days, auto& costs, int bal, int idx) {  <-- unecceasay dim of bal
        if (idx == days.size()) return 0;
        if (dp[idx][bal] != -1) return dp[idx][bal];
        int a = 0;
        int b = 0;
        int c = 0;
        if (days[idx] <= bal) 
            return g(dp,days, costs, bal,idx + 1);
        
         
        a = costs[0] + g(dp,days, costs, 0, idx + 1);
        b = costs[1] + g(dp,days, costs, days[idx] + 6, idx + 1);
        c = costs[2] + g(dp,days, costs, days[idx] + 29, idx + 1);
        return dp[idx][bal] = min({a, b, c});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(365, vector<int>(365 + 30, -1));
        return g(dp,days, costs, 0, 0);
    }
};

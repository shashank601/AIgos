class Solution {
public:
    int climbStairs(int n) {
        vector<int> stair(n + 1);
        stair[0] = 1;
        stair[1] = 1;

        for (int i = 2; i <= n; i++) {
            stair[i] = stair[i - 1] + stair[i - 2];
        }

        return stair.back();


    }
};

  
dp[i] => how many valid sequences exist that reach step i
dp[0] => 1 bcz empty seq "" i still a valid one 
dp[1] => 1 bcz  "1"

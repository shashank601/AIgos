class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);

        dp[0] = 1;

        for (int i = 0; i <= target; i++) {
            for (auto& num : nums) {                <--- donot flip the order ! since its a permuattion problem we need exposure of all nums in same iter at every cell
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};

====

i am not confident
whether i memorized or actually understood

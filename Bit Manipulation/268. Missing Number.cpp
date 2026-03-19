class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};


1^2^3^4^...^n^nums[0]^nums[1]^nums[2]..

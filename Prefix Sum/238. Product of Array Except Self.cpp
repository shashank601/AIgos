class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = nums[0];
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i];
        }

        int suff = 1;
        for (int i = n - 1; i >= 1; i--) {    <--- i >= 1 and not 0
            ans[i] = suff * ans[i - 1];
            suff *= nums[i];
        }
        ans[0] = suff;
        return ans;
    }
};



     

        

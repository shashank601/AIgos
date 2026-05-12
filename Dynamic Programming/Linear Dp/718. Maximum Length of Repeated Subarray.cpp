not a lcs

class Solution {
public:
    vector<vector<int>> dp;
    Solution() {
        // dp.assign(,vector<int>(, 0));
    }

    int ans = 0;

    int g(vector<int>& n1, vector<int>& n2 , int i, int j) {
        
        if (i == n1.size() || j == n2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int res1 = 0;
        if (n1[i] == n2[j]) {
            res1 = g(n1, n2, i + 1, j + 1) + 1;
            ans = max(res1, ans);
        }


        g(n1, n2, i, j + 1);    <-- chain breaks
        g(n1, n2, i + 1, j);    <-- same  (implies do a fresh start from i + 1, j;     from there we will watch for 'ans')

        return dp[i][j] = res1;
       
    }


    int findLength(vector<int>& nums1, vector<int>& nums2) {
        dp.assign(nums1.size() + 1, vector<int>(nums2.size() + 1, -1));
        g(nums1, nums2, 0, 0);
        return ans;
    }
};

=========

better way to see chain breaking

int g(vector<int>& a, vector<int>& b, int i, int j) {

    if (i == a.size() || j == b.size()) return 0;
  
    if (a[i] == b[j]) {
        return 1 + g(a, b, i + 1, j + 1);
    }

    return 0;          <-- !!!       or g(), g()
}

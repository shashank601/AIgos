class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int ans = 0;

        if (n2 % 2 == 1) {
            for (int x : nums1) {
                ans ^= x;
            }
        }

        if (n1 % 2 == 1) {
            for (int x : nums2) {
                ans ^= x;
            }
        }

        return ans;
    }
};

simple property exploitation

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int resXor = 0;
        for (auto val : nums) {
            resXor ^= val;
        }
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            if (((resXor >> i) & 1) != ((k >> i) & 1)) cnt++;     ---> on mismatch flip
        }
        return cnt;
    }
};


ineff v: O(n*32)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // vector<int> acc(32);
        
        int cnt = 0;


        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int ones = 0;
            for (auto num : nums) {
                if ((num >> i) & 1) {
                    ones++;
                }
            }

            if ((ones % 2) != ((k >> i) & 1)) {
                cnt++;
            } 
        }

        return cnt;
    }
};

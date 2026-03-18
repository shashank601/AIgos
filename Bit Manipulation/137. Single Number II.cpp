class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask = 0;

        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (auto num : nums) {
                if ((num >> i) & 1) cnt++;
            }

            if (cnt % 3 != 0) {   <--- if sum is not div by 3 it means there extra set bit there
                mask |= 1 << i;
            }
        }

        return mask;
    }
};

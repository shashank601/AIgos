class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        int sm = INT_MAX;
        int lg = INT_MIN;

        for (auto i : nums) {
            sm = min(sm, i);
            lg = max(lg, i);
        }


        while (lg && sm) {                  <-- not std way to take gcd
            if (lg > sm) {
                lg = lg % sm;
            } else {
                sm = sm % lg;
            }
        }

        return max(lg, sm);
    }
};

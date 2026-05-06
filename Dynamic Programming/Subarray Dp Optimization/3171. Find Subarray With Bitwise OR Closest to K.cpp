class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        unordered_set<int> prev, curr;
        int diff = INT_MAX;

        for (auto& val : nums) {
            curr.clear();
            curr.insert(val);
            diff = min(abs(val - k), diff);
            for (auto& old_val : prev) {
                int new_val = old_val | val;
                diff = min(abs(new_val - k), diff);
                curr.insert(new_val);
            }
            prev = curr;
        }
        return diff;
    }
};

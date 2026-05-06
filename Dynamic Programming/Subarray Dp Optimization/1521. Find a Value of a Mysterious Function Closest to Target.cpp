class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> prev, curr;
        int diff = INT_MAX;
        for (auto& val : arr) {
            curr.clear();
            diff = min(abs(val - target), diff);

            curr.insert(val); 

            for (auto& old_val : prev) {
                int new_val = old_val & val;
                diff = min(abs(new_val - target), diff);
                curr.insert(new_val);
            }       
            prev = curr;
        } 

        return diff;
    }
};

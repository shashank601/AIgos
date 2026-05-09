class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        auto& need = capacity;
        for (int i = 0; i < capacity.size(); i++) {
            need[i] = capacity[i] - rocks[i];
        }
        sort(need.begin(), need.end());
        
        int ans = 0;
        for (auto& required : need) {
            if (additionalRocks >= required) {
                additionalRocks -= required;
                ans++;
            } 
        }
        return ans;
    }
};
